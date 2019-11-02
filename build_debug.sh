# set generator for cmake creating
generator="Unix Makefiles"

# delete debug cache
rm -rf "bin/$generator"
mkdir "bin/$generator"

# use generator
echo ---------------------------------------
echo Current generator: $generator
echo ""
echo Command is:
echo     cd "bin/$generator"
echo     cmake --verbose -G "$generator" "../../src/"
echo     make "bin/$generator"
echo ""

cd "bin/$generator"
cmake --verbose -G "$generator" "../../src/"
make

echo ""
echo ""
echo Generator executed.

# end of the program
read -p "Press [Enter] key to exit script..."

exit 0
