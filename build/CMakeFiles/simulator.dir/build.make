# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/suisei/projects/research/mmg_simulator/mmg_simulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/suisei/projects/research/mmg_simulator/mmg_simulator/build

# Include any dependencies generated for this target.
include CMakeFiles/simulator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/simulator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/simulator.dir/flags.make

CMakeFiles/simulator.dir/src/simulator.cpp.o: CMakeFiles/simulator.dir/flags.make
CMakeFiles/simulator.dir/src/simulator.cpp.o: ../src/simulator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/suisei/projects/research/mmg_simulator/mmg_simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/simulator.dir/src/simulator.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/simulator.dir/src/simulator.cpp.o -c /home/suisei/projects/research/mmg_simulator/mmg_simulator/src/simulator.cpp

CMakeFiles/simulator.dir/src/simulator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/simulator.dir/src/simulator.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/suisei/projects/research/mmg_simulator/mmg_simulator/src/simulator.cpp > CMakeFiles/simulator.dir/src/simulator.cpp.i

CMakeFiles/simulator.dir/src/simulator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/simulator.dir/src/simulator.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/suisei/projects/research/mmg_simulator/mmg_simulator/src/simulator.cpp -o CMakeFiles/simulator.dir/src/simulator.cpp.s

CMakeFiles/simulator.dir/src/simulator.cpp.o.requires:

.PHONY : CMakeFiles/simulator.dir/src/simulator.cpp.o.requires

CMakeFiles/simulator.dir/src/simulator.cpp.o.provides: CMakeFiles/simulator.dir/src/simulator.cpp.o.requires
	$(MAKE) -f CMakeFiles/simulator.dir/build.make CMakeFiles/simulator.dir/src/simulator.cpp.o.provides.build
.PHONY : CMakeFiles/simulator.dir/src/simulator.cpp.o.provides

CMakeFiles/simulator.dir/src/simulator.cpp.o.provides.build: CMakeFiles/simulator.dir/src/simulator.cpp.o


# Object files for target simulator
simulator_OBJECTS = \
"CMakeFiles/simulator.dir/src/simulator.cpp.o"

# External object files for target simulator
simulator_EXTERNAL_OBJECTS =

simulator: CMakeFiles/simulator.dir/src/simulator.cpp.o
simulator: CMakeFiles/simulator.dir/build.make
simulator: libmmg_models.a
simulator: libmmg_parameter.a
simulator: CMakeFiles/simulator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/suisei/projects/research/mmg_simulator/mmg_simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable simulator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/simulator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/simulator.dir/build: simulator

.PHONY : CMakeFiles/simulator.dir/build

CMakeFiles/simulator.dir/requires: CMakeFiles/simulator.dir/src/simulator.cpp.o.requires

.PHONY : CMakeFiles/simulator.dir/requires

CMakeFiles/simulator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/simulator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/simulator.dir/clean

CMakeFiles/simulator.dir/depend:
	cd /home/suisei/projects/research/mmg_simulator/mmg_simulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/suisei/projects/research/mmg_simulator/mmg_simulator /home/suisei/projects/research/mmg_simulator/mmg_simulator /home/suisei/projects/research/mmg_simulator/mmg_simulator/build /home/suisei/projects/research/mmg_simulator/mmg_simulator/build /home/suisei/projects/research/mmg_simulator/mmg_simulator/build/CMakeFiles/simulator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/simulator.dir/depend

