# base settings for cmake
cmake_minimum_required(VERSION 3.3)
set(PROJECT_TARGET_NAME eagle_server)
project(${PROJECT_TARGET_NAME})

# temporary global linking
set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS}")
set(CMAKE_CXX_STANDARD 11)

# 
string(TOLOWER ${CMAKE_GENERATOR} bin_dir)
set(directory "${PROJECT_BINARY_DIR}/bin")
file(MAKE_DIRECTORY ${directory})
message("Generator: ${bin_dir}")
message("Build directory: ${directory}")

# set output folders
# libs	
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY
        ${directory}
        CACHE PATH
        "Single Directory for all"
        )
# executables
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY
        ${directory}
        CACHE PATH
        "Single Directory for all"
        )
# libs .a
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY
        ${directory}
        CACHE PATH
        "Single Directory for all"
        )
		
# text encoding for compiler
# add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
# add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

# enable testing
# enable_testing()

add_subdirectory(fsmanager)
#add_subdirectory(domain_redirecter)
#add_subdirectory(basic_controller)
#add_subdirectory(httpd_listener)
#add_subdirectory(implementations)

#add_subdirectory(tests)

# not released yet
#add_subdirectory(external_modules)

# checking build type on platform
if (WIN32) # building on windows
	message("Cmake build for windows")
	add_subdirectory(eagle)
elseif (MSVC) # building on visual c++
	message("Cmake build for visual c++")
	add_subdirectory(eagle)
elseif (UNIX) # building on unix (mac, linux)
	message("Cmake build for unix")
	#add_subdirectory(muxa_application_unix)
	add_subdirectory(eagle)
endif (WIN32)

# if testing
#if(BUILD_TESTING)
#	add_test(FirstTest Test 1)
#endif()
