# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/student/CLionProjects/Snake2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/student/CLionProjects/Snake2/target

# Utility rule file for check.

# Include the progress variables for this target.
include Biblioteka/CMakeFiles/check.dir/progress.make

Biblioteka/CMakeFiles/check:
	/usr/bin/cmake -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all /usr/bin/ctest -C Debug --verbose

check: Biblioteka/CMakeFiles/check
check: Biblioteka/CMakeFiles/check.dir/build.make

.PHONY : check

# Rule to build all files generated by this target.
Biblioteka/CMakeFiles/check.dir/build: check

.PHONY : Biblioteka/CMakeFiles/check.dir/build

Biblioteka/CMakeFiles/check.dir/clean:
	cd /home/student/CLionProjects/Snake2/target/Biblioteka && $(CMAKE_COMMAND) -P CMakeFiles/check.dir/cmake_clean.cmake
.PHONY : Biblioteka/CMakeFiles/check.dir/clean

Biblioteka/CMakeFiles/check.dir/depend:
	cd /home/student/CLionProjects/Snake2/target && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student/CLionProjects/Snake2 /home/student/CLionProjects/Snake2/Biblioteka /home/student/CLionProjects/Snake2/target /home/student/CLionProjects/Snake2/target/Biblioteka /home/student/CLionProjects/Snake2/target/Biblioteka/CMakeFiles/check.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Biblioteka/CMakeFiles/check.dir/depend

