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
include include/eigen/bench/spbench/CMakeFiles/spsolver.dir/depend.make

# Include the progress variables for this target.
include include/eigen/bench/spbench/CMakeFiles/spsolver.dir/progress.make

# Include the compile flags for this target's objects.
include include/eigen/bench/spbench/CMakeFiles/spsolver.dir/flags.make

include/eigen/bench/spbench/CMakeFiles/spsolver.dir/sp_solver.cpp.o: include/eigen/bench/spbench/CMakeFiles/spsolver.dir/flags.make
include/eigen/bench/spbench/CMakeFiles/spsolver.dir/sp_solver.cpp.o: ../include/eigen/bench/spbench/sp_solver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object include/eigen/bench/spbench/CMakeFiles/spsolver.dir/sp_solver.cpp.o"
	cd /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build/include/eigen/bench/spbench && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/spsolver.dir/sp_solver.cpp.o -c /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/include/eigen/bench/spbench/sp_solver.cpp

include/eigen/bench/spbench/CMakeFiles/spsolver.dir/sp_solver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/spsolver.dir/sp_solver.cpp.i"
	cd /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build/include/eigen/bench/spbench && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/include/eigen/bench/spbench/sp_solver.cpp > CMakeFiles/spsolver.dir/sp_solver.cpp.i

include/eigen/bench/spbench/CMakeFiles/spsolver.dir/sp_solver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/spsolver.dir/sp_solver.cpp.s"
	cd /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build/include/eigen/bench/spbench && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/include/eigen/bench/spbench/sp_solver.cpp -o CMakeFiles/spsolver.dir/sp_solver.cpp.s

include/eigen/bench/spbench/CMakeFiles/spsolver.dir/sp_solver.cpp.o.requires:

.PHONY : include/eigen/bench/spbench/CMakeFiles/spsolver.dir/sp_solver.cpp.o.requires

include/eigen/bench/spbench/CMakeFiles/spsolver.dir/sp_solver.cpp.o.provides: include/eigen/bench/spbench/CMakeFiles/spsolver.dir/sp_solver.cpp.o.requires
	$(MAKE) -f include/eigen/bench/spbench/CMakeFiles/spsolver.dir/build.make include/eigen/bench/spbench/CMakeFiles/spsolver.dir/sp_solver.cpp.o.provides.build
.PHONY : include/eigen/bench/spbench/CMakeFiles/spsolver.dir/sp_solver.cpp.o.provides

include/eigen/bench/spbench/CMakeFiles/spsolver.dir/sp_solver.cpp.o.provides.build: include/eigen/bench/spbench/CMakeFiles/spsolver.dir/sp_solver.cpp.o


# Object files for target spsolver
spsolver_OBJECTS = \
"CMakeFiles/spsolver.dir/sp_solver.cpp.o"

# External object files for target spsolver
spsolver_EXTERNAL_OBJECTS =

include/eigen/bench/spbench/spsolver: include/eigen/bench/spbench/CMakeFiles/spsolver.dir/sp_solver.cpp.o
include/eigen/bench/spbench/spsolver: include/eigen/bench/spbench/CMakeFiles/spsolver.dir/build.make
include/eigen/bench/spbench/spsolver: /usr/lib/x86_64-linux-gnu/libsuperlu.so
include/eigen/bench/spbench/spsolver: include/eigen/blas/libeigen_blas_static.a
include/eigen/bench/spbench/spsolver: /usr/lib/x86_64-linux-gnu/librt.so
include/eigen/bench/spbench/spsolver: include/eigen/bench/spbench/CMakeFiles/spsolver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable spsolver"
	cd /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build/include/eigen/bench/spbench && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/spsolver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
include/eigen/bench/spbench/CMakeFiles/spsolver.dir/build: include/eigen/bench/spbench/spsolver

.PHONY : include/eigen/bench/spbench/CMakeFiles/spsolver.dir/build

include/eigen/bench/spbench/CMakeFiles/spsolver.dir/requires: include/eigen/bench/spbench/CMakeFiles/spsolver.dir/sp_solver.cpp.o.requires

.PHONY : include/eigen/bench/spbench/CMakeFiles/spsolver.dir/requires

include/eigen/bench/spbench/CMakeFiles/spsolver.dir/clean:
	cd /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build/include/eigen/bench/spbench && $(CMAKE_COMMAND) -P CMakeFiles/spsolver.dir/cmake_clean.cmake
.PHONY : include/eigen/bench/spbench/CMakeFiles/spsolver.dir/clean

include/eigen/bench/spbench/CMakeFiles/spsolver.dir/depend:
	cd /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/include/eigen/bench/spbench /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build/include/eigen/bench/spbench /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build/include/eigen/bench/spbench/CMakeFiles/spsolver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : include/eigen/bench/spbench/CMakeFiles/spsolver.dir/depend

