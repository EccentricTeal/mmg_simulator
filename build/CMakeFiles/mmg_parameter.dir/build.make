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
CMAKE_SOURCE_DIR = /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build

# Include any dependencies generated for this target.
include CMakeFiles/mmg_parameter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mmg_parameter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mmg_parameter.dir/flags.make

CMakeFiles/mmg_parameter.dir/src/mmg_parameter.cpp.o: CMakeFiles/mmg_parameter.dir/flags.make
CMakeFiles/mmg_parameter.dir/src/mmg_parameter.cpp.o: ../src/mmg_parameter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mmg_parameter.dir/src/mmg_parameter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mmg_parameter.dir/src/mmg_parameter.cpp.o -c /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/src/mmg_parameter.cpp

CMakeFiles/mmg_parameter.dir/src/mmg_parameter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mmg_parameter.dir/src/mmg_parameter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/src/mmg_parameter.cpp > CMakeFiles/mmg_parameter.dir/src/mmg_parameter.cpp.i

CMakeFiles/mmg_parameter.dir/src/mmg_parameter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mmg_parameter.dir/src/mmg_parameter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/src/mmg_parameter.cpp -o CMakeFiles/mmg_parameter.dir/src/mmg_parameter.cpp.s

CMakeFiles/mmg_parameter.dir/src/mmg_parameter.cpp.o.requires:

.PHONY : CMakeFiles/mmg_parameter.dir/src/mmg_parameter.cpp.o.requires

CMakeFiles/mmg_parameter.dir/src/mmg_parameter.cpp.o.provides: CMakeFiles/mmg_parameter.dir/src/mmg_parameter.cpp.o.requires
	$(MAKE) -f CMakeFiles/mmg_parameter.dir/build.make CMakeFiles/mmg_parameter.dir/src/mmg_parameter.cpp.o.provides.build
.PHONY : CMakeFiles/mmg_parameter.dir/src/mmg_parameter.cpp.o.provides

CMakeFiles/mmg_parameter.dir/src/mmg_parameter.cpp.o.provides.build: CMakeFiles/mmg_parameter.dir/src/mmg_parameter.cpp.o


# Object files for target mmg_parameter
mmg_parameter_OBJECTS = \
"CMakeFiles/mmg_parameter.dir/src/mmg_parameter.cpp.o"

# External object files for target mmg_parameter
mmg_parameter_EXTERNAL_OBJECTS =

libmmg_parameter.a: CMakeFiles/mmg_parameter.dir/src/mmg_parameter.cpp.o
libmmg_parameter.a: CMakeFiles/mmg_parameter.dir/build.make
libmmg_parameter.a: CMakeFiles/mmg_parameter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmmg_parameter.a"
	$(CMAKE_COMMAND) -P CMakeFiles/mmg_parameter.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mmg_parameter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mmg_parameter.dir/build: libmmg_parameter.a

.PHONY : CMakeFiles/mmg_parameter.dir/build

CMakeFiles/mmg_parameter.dir/requires: CMakeFiles/mmg_parameter.dir/src/mmg_parameter.cpp.o.requires

.PHONY : CMakeFiles/mmg_parameter.dir/requires

CMakeFiles/mmg_parameter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mmg_parameter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mmg_parameter.dir/clean

CMakeFiles/mmg_parameter.dir/depend:
	cd /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build/CMakeFiles/mmg_parameter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mmg_parameter.dir/depend

