# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_SOURCE_DIR = /home/exe/PadDemo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/exe/PadDemo/cmake-build-debug-remote-pad

# Include any dependencies generated for this target.
include CMakeFiles/PadDemo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PadDemo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PadDemo.dir/flags.make

CMakeFiles/PadDemo.dir/I2CDriver.cpp.o: CMakeFiles/PadDemo.dir/flags.make
CMakeFiles/PadDemo.dir/I2CDriver.cpp.o: ../I2CDriver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/exe/PadDemo/cmake-build-debug-remote-pad/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PadDemo.dir/I2CDriver.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PadDemo.dir/I2CDriver.cpp.o -c /home/exe/PadDemo/I2CDriver.cpp

CMakeFiles/PadDemo.dir/I2CDriver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PadDemo.dir/I2CDriver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/exe/PadDemo/I2CDriver.cpp > CMakeFiles/PadDemo.dir/I2CDriver.cpp.i

CMakeFiles/PadDemo.dir/I2CDriver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PadDemo.dir/I2CDriver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/exe/PadDemo/I2CDriver.cpp -o CMakeFiles/PadDemo.dir/I2CDriver.cpp.s

CMakeFiles/PadDemo.dir/SH3001Driver.cpp.o: CMakeFiles/PadDemo.dir/flags.make
CMakeFiles/PadDemo.dir/SH3001Driver.cpp.o: ../SH3001Driver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/exe/PadDemo/cmake-build-debug-remote-pad/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PadDemo.dir/SH3001Driver.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PadDemo.dir/SH3001Driver.cpp.o -c /home/exe/PadDemo/SH3001Driver.cpp

CMakeFiles/PadDemo.dir/SH3001Driver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PadDemo.dir/SH3001Driver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/exe/PadDemo/SH3001Driver.cpp > CMakeFiles/PadDemo.dir/SH3001Driver.cpp.i

CMakeFiles/PadDemo.dir/SH3001Driver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PadDemo.dir/SH3001Driver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/exe/PadDemo/SH3001Driver.cpp -o CMakeFiles/PadDemo.dir/SH3001Driver.cpp.s

CMakeFiles/PadDemo.dir/main.cpp.o: CMakeFiles/PadDemo.dir/flags.make
CMakeFiles/PadDemo.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/exe/PadDemo/cmake-build-debug-remote-pad/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/PadDemo.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PadDemo.dir/main.cpp.o -c /home/exe/PadDemo/main.cpp

CMakeFiles/PadDemo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PadDemo.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/exe/PadDemo/main.cpp > CMakeFiles/PadDemo.dir/main.cpp.i

CMakeFiles/PadDemo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PadDemo.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/exe/PadDemo/main.cpp -o CMakeFiles/PadDemo.dir/main.cpp.s

# Object files for target PadDemo
PadDemo_OBJECTS = \
"CMakeFiles/PadDemo.dir/I2CDriver.cpp.o" \
"CMakeFiles/PadDemo.dir/SH3001Driver.cpp.o" \
"CMakeFiles/PadDemo.dir/main.cpp.o"

# External object files for target PadDemo
PadDemo_EXTERNAL_OBJECTS =

PadDemo: CMakeFiles/PadDemo.dir/I2CDriver.cpp.o
PadDemo: CMakeFiles/PadDemo.dir/SH3001Driver.cpp.o
PadDemo: CMakeFiles/PadDemo.dir/main.cpp.o
PadDemo: CMakeFiles/PadDemo.dir/build.make
PadDemo: CMakeFiles/PadDemo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/exe/PadDemo/cmake-build-debug-remote-pad/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable PadDemo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PadDemo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PadDemo.dir/build: PadDemo

.PHONY : CMakeFiles/PadDemo.dir/build

CMakeFiles/PadDemo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PadDemo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PadDemo.dir/clean

CMakeFiles/PadDemo.dir/depend:
	cd /home/exe/PadDemo/cmake-build-debug-remote-pad && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/exe/PadDemo /home/exe/PadDemo /home/exe/PadDemo/cmake-build-debug-remote-pad /home/exe/PadDemo/cmake-build-debug-remote-pad /home/exe/PadDemo/cmake-build-debug-remote-pad/CMakeFiles/PadDemo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PadDemo.dir/depend

