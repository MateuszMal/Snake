# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/student/clion-2019.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/student/clion-2019.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/student/CLionProjects/Snake2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/student/CLionProjects/Snake2/cmake-build-debug

# Include any dependencies generated for this target.
include Biblioteka/CMakeFiles/Biblioteka.dir/depend.make

# Include the progress variables for this target.
include Biblioteka/CMakeFiles/Biblioteka.dir/progress.make

# Include the compile flags for this target's objects.
include Biblioteka/CMakeFiles/Biblioteka.dir/flags.make

Biblioteka/CMakeFiles/Biblioteka.dir/src/Food.cpp.o: Biblioteka/CMakeFiles/Biblioteka.dir/flags.make
Biblioteka/CMakeFiles/Biblioteka.dir/src/Food.cpp.o: ../Biblioteka/src/Food.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CLionProjects/Snake2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Biblioteka/CMakeFiles/Biblioteka.dir/src/Food.cpp.o"
	cd /home/student/CLionProjects/Snake2/cmake-build-debug/Biblioteka && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Biblioteka.dir/src/Food.cpp.o -c /home/student/CLionProjects/Snake2/Biblioteka/src/Food.cpp

Biblioteka/CMakeFiles/Biblioteka.dir/src/Food.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Biblioteka.dir/src/Food.cpp.i"
	cd /home/student/CLionProjects/Snake2/cmake-build-debug/Biblioteka && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/CLionProjects/Snake2/Biblioteka/src/Food.cpp > CMakeFiles/Biblioteka.dir/src/Food.cpp.i

Biblioteka/CMakeFiles/Biblioteka.dir/src/Food.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Biblioteka.dir/src/Food.cpp.s"
	cd /home/student/CLionProjects/Snake2/cmake-build-debug/Biblioteka && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/CLionProjects/Snake2/Biblioteka/src/Food.cpp -o CMakeFiles/Biblioteka.dir/src/Food.cpp.s

Biblioteka/CMakeFiles/Biblioteka.dir/src/Snake.cpp.o: Biblioteka/CMakeFiles/Biblioteka.dir/flags.make
Biblioteka/CMakeFiles/Biblioteka.dir/src/Snake.cpp.o: ../Biblioteka/src/Snake.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CLionProjects/Snake2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Biblioteka/CMakeFiles/Biblioteka.dir/src/Snake.cpp.o"
	cd /home/student/CLionProjects/Snake2/cmake-build-debug/Biblioteka && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Biblioteka.dir/src/Snake.cpp.o -c /home/student/CLionProjects/Snake2/Biblioteka/src/Snake.cpp

Biblioteka/CMakeFiles/Biblioteka.dir/src/Snake.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Biblioteka.dir/src/Snake.cpp.i"
	cd /home/student/CLionProjects/Snake2/cmake-build-debug/Biblioteka && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/CLionProjects/Snake2/Biblioteka/src/Snake.cpp > CMakeFiles/Biblioteka.dir/src/Snake.cpp.i

Biblioteka/CMakeFiles/Biblioteka.dir/src/Snake.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Biblioteka.dir/src/Snake.cpp.s"
	cd /home/student/CLionProjects/Snake2/cmake-build-debug/Biblioteka && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/CLionProjects/Snake2/Biblioteka/src/Snake.cpp -o CMakeFiles/Biblioteka.dir/src/Snake.cpp.s

Biblioteka/CMakeFiles/Biblioteka.dir/test/master.cpp.o: Biblioteka/CMakeFiles/Biblioteka.dir/flags.make
Biblioteka/CMakeFiles/Biblioteka.dir/test/master.cpp.o: ../Biblioteka/test/master.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CLionProjects/Snake2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Biblioteka/CMakeFiles/Biblioteka.dir/test/master.cpp.o"
	cd /home/student/CLionProjects/Snake2/cmake-build-debug/Biblioteka && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Biblioteka.dir/test/master.cpp.o -c /home/student/CLionProjects/Snake2/Biblioteka/test/master.cpp

Biblioteka/CMakeFiles/Biblioteka.dir/test/master.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Biblioteka.dir/test/master.cpp.i"
	cd /home/student/CLionProjects/Snake2/cmake-build-debug/Biblioteka && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/CLionProjects/Snake2/Biblioteka/test/master.cpp > CMakeFiles/Biblioteka.dir/test/master.cpp.i

Biblioteka/CMakeFiles/Biblioteka.dir/test/master.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Biblioteka.dir/test/master.cpp.s"
	cd /home/student/CLionProjects/Snake2/cmake-build-debug/Biblioteka && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/CLionProjects/Snake2/Biblioteka/test/master.cpp -o CMakeFiles/Biblioteka.dir/test/master.cpp.s

Biblioteka/CMakeFiles/Biblioteka.dir/src/Settings.cpp.o: Biblioteka/CMakeFiles/Biblioteka.dir/flags.make
Biblioteka/CMakeFiles/Biblioteka.dir/src/Settings.cpp.o: ../Biblioteka/src/Settings.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CLionProjects/Snake2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object Biblioteka/CMakeFiles/Biblioteka.dir/src/Settings.cpp.o"
	cd /home/student/CLionProjects/Snake2/cmake-build-debug/Biblioteka && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Biblioteka.dir/src/Settings.cpp.o -c /home/student/CLionProjects/Snake2/Biblioteka/src/Settings.cpp

Biblioteka/CMakeFiles/Biblioteka.dir/src/Settings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Biblioteka.dir/src/Settings.cpp.i"
	cd /home/student/CLionProjects/Snake2/cmake-build-debug/Biblioteka && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/CLionProjects/Snake2/Biblioteka/src/Settings.cpp > CMakeFiles/Biblioteka.dir/src/Settings.cpp.i

Biblioteka/CMakeFiles/Biblioteka.dir/src/Settings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Biblioteka.dir/src/Settings.cpp.s"
	cd /home/student/CLionProjects/Snake2/cmake-build-debug/Biblioteka && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/CLionProjects/Snake2/Biblioteka/src/Settings.cpp -o CMakeFiles/Biblioteka.dir/src/Settings.cpp.s

Biblioteka/CMakeFiles/Biblioteka.dir/src/gameFunctions.cpp.o: Biblioteka/CMakeFiles/Biblioteka.dir/flags.make
Biblioteka/CMakeFiles/Biblioteka.dir/src/gameFunctions.cpp.o: ../Biblioteka/src/gameFunctions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/student/CLionProjects/Snake2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object Biblioteka/CMakeFiles/Biblioteka.dir/src/gameFunctions.cpp.o"
	cd /home/student/CLionProjects/Snake2/cmake-build-debug/Biblioteka && /usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Biblioteka.dir/src/gameFunctions.cpp.o -c /home/student/CLionProjects/Snake2/Biblioteka/src/gameFunctions.cpp

Biblioteka/CMakeFiles/Biblioteka.dir/src/gameFunctions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Biblioteka.dir/src/gameFunctions.cpp.i"
	cd /home/student/CLionProjects/Snake2/cmake-build-debug/Biblioteka && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/student/CLionProjects/Snake2/Biblioteka/src/gameFunctions.cpp > CMakeFiles/Biblioteka.dir/src/gameFunctions.cpp.i

Biblioteka/CMakeFiles/Biblioteka.dir/src/gameFunctions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Biblioteka.dir/src/gameFunctions.cpp.s"
	cd /home/student/CLionProjects/Snake2/cmake-build-debug/Biblioteka && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/student/CLionProjects/Snake2/Biblioteka/src/gameFunctions.cpp -o CMakeFiles/Biblioteka.dir/src/gameFunctions.cpp.s

# Object files for target Biblioteka
Biblioteka_OBJECTS = \
"CMakeFiles/Biblioteka.dir/src/Food.cpp.o" \
"CMakeFiles/Biblioteka.dir/src/Snake.cpp.o" \
"CMakeFiles/Biblioteka.dir/test/master.cpp.o" \
"CMakeFiles/Biblioteka.dir/src/Settings.cpp.o" \
"CMakeFiles/Biblioteka.dir/src/gameFunctions.cpp.o"

# External object files for target Biblioteka
Biblioteka_EXTERNAL_OBJECTS =

Biblioteka/libBiblioteka.a: Biblioteka/CMakeFiles/Biblioteka.dir/src/Food.cpp.o
Biblioteka/libBiblioteka.a: Biblioteka/CMakeFiles/Biblioteka.dir/src/Snake.cpp.o
Biblioteka/libBiblioteka.a: Biblioteka/CMakeFiles/Biblioteka.dir/test/master.cpp.o
Biblioteka/libBiblioteka.a: Biblioteka/CMakeFiles/Biblioteka.dir/src/Settings.cpp.o
Biblioteka/libBiblioteka.a: Biblioteka/CMakeFiles/Biblioteka.dir/src/gameFunctions.cpp.o
Biblioteka/libBiblioteka.a: Biblioteka/CMakeFiles/Biblioteka.dir/build.make
Biblioteka/libBiblioteka.a: Biblioteka/CMakeFiles/Biblioteka.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/student/CLionProjects/Snake2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libBiblioteka.a"
	cd /home/student/CLionProjects/Snake2/cmake-build-debug/Biblioteka && $(CMAKE_COMMAND) -P CMakeFiles/Biblioteka.dir/cmake_clean_target.cmake
	cd /home/student/CLionProjects/Snake2/cmake-build-debug/Biblioteka && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Biblioteka.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Biblioteka/CMakeFiles/Biblioteka.dir/build: Biblioteka/libBiblioteka.a

.PHONY : Biblioteka/CMakeFiles/Biblioteka.dir/build

Biblioteka/CMakeFiles/Biblioteka.dir/clean:
	cd /home/student/CLionProjects/Snake2/cmake-build-debug/Biblioteka && $(CMAKE_COMMAND) -P CMakeFiles/Biblioteka.dir/cmake_clean.cmake
.PHONY : Biblioteka/CMakeFiles/Biblioteka.dir/clean

Biblioteka/CMakeFiles/Biblioteka.dir/depend:
	cd /home/student/CLionProjects/Snake2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/student/CLionProjects/Snake2 /home/student/CLionProjects/Snake2/Biblioteka /home/student/CLionProjects/Snake2/cmake-build-debug /home/student/CLionProjects/Snake2/cmake-build-debug/Biblioteka /home/student/CLionProjects/Snake2/cmake-build-debug/Biblioteka/CMakeFiles/Biblioteka.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Biblioteka/CMakeFiles/Biblioteka.dir/depend

