#!/bin/bash
# ------------------------------------------------------------------
# [Ravin A.] Cmake project builder
#            Script builds entry cmake project by generator.
# ------------------------------------------------------------------

# set default generator for cmake
default_generator="CodeLite - Unix Makefiles"
using_generator=""

VERSION=0.1.0
TITLE=cpb-eagle-debug
SUBJECT=$TITLE-$VERSION-process
USAGE="Usage: command -hgv [generator]"

# --- Options locking on empty -------------------------------------
if [ $# == 0 ] ; then
    echo $USAGE
    using_generator="$default_generator"
else
    using_generator=$1
fi

# --- Options processing -------------------------------------------
while getopts ":i:vhg" optname
  do
    case "$optname" in
      "v")
        echo "Version $VERSION"
        exit 0;
        ;;
      "g")
        echo "default generator: $default_generator"
        exit 0;
        ;;
      "h")
        echo $USAGE
        exit 0;
        ;;
      "?")
        echo "Unknown option $OPTARG"
        exit 0;
        ;;
      ":")
        echo "No argument value for option $OPTARG"
        exit 0;
        ;;
      *)
        echo "Unknown error while processing options"
        exit 0;
        ;;
    esac
  done

shift $(($OPTIND - 1))

# --- Locks -------------------------------------------------------
LOCK_FILE=/tmp/$SUBJECT.lock
if [ -f "$LOCK_FILE" ]; then
   echo "Script is already running"
   exit
fi

trap "rm -f $LOCK_FILE" EXIT
touch $LOCK_FILE

# --- Body --------------------------------------------------------
#  SCRIPT LOGIC GOES HERE

# delete debug cache
rm -rf "bin/$using_generator"
mkdir "bin/$using_generator"

# use generator
echo ---------------------------------------
echo Current generator: $using_generator
echo

cd "bin/$using_generator"
cmake --verbose -G "$using_generator" "../../src/" -DCMAKE_BUILD_TYPE=Debug
make

echo ""
echo ""
echo Generator executed.

# end of the program
read -p "Press [Enter] key to exit script..."

# -----------------------------------------------------------------
