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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/suisei/windata/projects/research/doctor/projects/mmg_simulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build

# Include any dependencies generated for this target.
include include/eigen/unsupported/doc/examples/CMakeFiles/example_MatrixSine.dir/depend.make

# Include the progress variables for this target.
include include/eigen/unsupported/doc/examples/CMakeFiles/example_MatrixSine.dir/progress.make

# Include the compile flags for this target's objects.
include include/eigen/unsupported/doc/examples/CMakeFiles/example_MatrixSine.dir/flags.make

include/eigen/unsupported/doc/examples/CMakeFiles/example_MatrixSine.dir/MatrixSine.cpp.o: include/eigen/unsupported/doc/examples/CMakeFiles/example_MatrixSine.dir/flags.make
include/eigen/unsupported/doc/examples/CMakeFiles/example_MatrixSine.dir/MatrixSine.cpp.o: ../include/eigen/unsupported/doc/examples/MatrixSine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object include/eigen/unsupported/doc/examples/CMakeFiles/example_MatrixSine.dir/MatrixSine.cpp.o"
	cd /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build/include/eigen/unsupported/doc/examples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/example_MatrixSine.dir/MatrixSine.cpp.o -c /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/include/eigen/unsupported/doc/examples/MatrixSine.cpp

include/eigen/unsupported/doc/examples/CMakeFiles/example_MatrixSine.dir/MatrixSine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example_MatrixSine.dir/MatrixSine.cpp.i"
	cd /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build/include/eigen/unsupported/doc/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/include/eigen/unsupported/doc/examples/MatrixSine.cpp > CMakeFiles/example_MatrixSine.dir/MatrixSine.cpp.i

include/eigen/unsupported/doc/examples/CMakeFiles/example_MatrixSine.dir/MatrixSine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example_MatrixSine.dir/MatrixSine.cpp.s"
	cd /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build/include/eigen/unsupported/doc/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/include/eigen/unsupported/doc/examples/MatrixSine.cpp -o CMakeFiles/example_MatrixSine.dir/MatrixSine.cpp.s

# Object files for target example_MatrixSine
example_MatrixSine_OBJECTS = \
"CMakeFiles/example_MatrixSine.dir/MatrixSine.cpp.o"

# External object files for target example_MatrixSine
example_MatrixSine_EXTERNAL_OBJECTS =

include/eigen/unsupported/doc/examples/example_MatrixSine: include/eigen/unsupported/doc/examples/CMakeFiles/example_MatrixSine.dir/MatrixSine.cpp.o
include/eigen/unsupported/doc/examples/example_MatrixSine: include/eigen/unsupported/doc/examples/CMakeFiles/example_MatrixSine.dir/build.make
include/eigen/unsupported/doc/examples/example_MatrixSine: include/eigen/unsupported/doc/examples/CMakeFiles/example_MatrixSine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable example_MatrixSine"
	cd /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build/include/eigen/unsupported/doc/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example_MatrixSine.dir/link.txt --verbose=$(VERBOSE)
	cd /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build/include/eigen/unsupported/doc/examples && ./example_MatrixSine >/home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build/include/eigen/unsupported/doc/examples/MatrixSine.out

# Rule to build all files generated by this target.
include/eigen/unsupported/doc/examples/CMakeFiles/example_MatrixSine.dir/build: include/eigen/unsupported/doc/examples/example_MatrixSine

.PHONY : include/eigen/unsupported/doc/examples/CMakeFiles/example_MatrixSine.dir/build

include/eigen/unsupported/doc/examples/CMakeFiles/example_MatrixSine.dir/clean:
	cd /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build/include/eigen/unsupported/doc/examples && $(CMAKE_COMMAND) -P CMakeFiles/example_MatrixSine.dir/cmake_clean.cmake
.PHONY : include/eigen/unsupported/doc/examples/CMakeFiles/example_MatrixSine.dir/clean

include/eigen/unsupported/doc/examples/CMakeFiles/example_MatrixSine.dir/depend:
	cd /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/suisei/windata/projects/research/doctor/projects/mmg_simulator /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/include/eigen/unsupported/doc/examples /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build/include/eigen/unsupported/doc/examples /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build/include/eigen/unsupported/doc/examples/CMakeFiles/example_MatrixSine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : include/eigen/unsupported/doc/examples/CMakeFiles/example_MatrixSine.dir/depend

