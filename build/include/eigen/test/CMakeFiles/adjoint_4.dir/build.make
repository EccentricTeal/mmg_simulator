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
include include/eigen/test/CMakeFiles/adjoint_4.dir/depend.make

# Include the progress variables for this target.
include include/eigen/test/CMakeFiles/adjoint_4.dir/progress.make

# Include the compile flags for this target's objects.
include include/eigen/test/CMakeFiles/adjoint_4.dir/flags.make

include/eigen/test/CMakeFiles/adjoint_4.dir/adjoint.cpp.o: include/eigen/test/CMakeFiles/adjoint_4.dir/flags.make
include/eigen/test/CMakeFiles/adjoint_4.dir/adjoint.cpp.o: ../include/eigen/test/adjoint.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object include/eigen/test/CMakeFiles/adjoint_4.dir/adjoint.cpp.o"
	cd /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build/include/eigen/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/adjoint_4.dir/adjoint.cpp.o -c /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/include/eigen/test/adjoint.cpp

include/eigen/test/CMakeFiles/adjoint_4.dir/adjoint.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/adjoint_4.dir/adjoint.cpp.i"
	cd /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build/include/eigen/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/include/eigen/test/adjoint.cpp > CMakeFiles/adjoint_4.dir/adjoint.cpp.i

include/eigen/test/CMakeFiles/adjoint_4.dir/adjoint.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/adjoint_4.dir/adjoint.cpp.s"
	cd /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build/include/eigen/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/include/eigen/test/adjoint.cpp -o CMakeFiles/adjoint_4.dir/adjoint.cpp.s

# Object files for target adjoint_4
adjoint_4_OBJECTS = \
"CMakeFiles/adjoint_4.dir/adjoint.cpp.o"

# External object files for target adjoint_4
adjoint_4_EXTERNAL_OBJECTS =

include/eigen/test/adjoint_4: include/eigen/test/CMakeFiles/adjoint_4.dir/adjoint.cpp.o
include/eigen/test/adjoint_4: include/eigen/test/CMakeFiles/adjoint_4.dir/build.make
include/eigen/test/adjoint_4: include/eigen/test/CMakeFiles/adjoint_4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable adjoint_4"
	cd /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build/include/eigen/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/adjoint_4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
include/eigen/test/CMakeFiles/adjoint_4.dir/build: include/eigen/test/adjoint_4

.PHONY : include/eigen/test/CMakeFiles/adjoint_4.dir/build

include/eigen/test/CMakeFiles/adjoint_4.dir/clean:
	cd /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build/include/eigen/test && $(CMAKE_COMMAND) -P CMakeFiles/adjoint_4.dir/cmake_clean.cmake
.PHONY : include/eigen/test/CMakeFiles/adjoint_4.dir/clean

include/eigen/test/CMakeFiles/adjoint_4.dir/depend:
	cd /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/suisei/windata/projects/research/doctor/projects/mmg_simulator /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/include/eigen/test /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build/include/eigen/test /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build/include/eigen/test/CMakeFiles/adjoint_4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : include/eigen/test/CMakeFiles/adjoint_4.dir/depend

