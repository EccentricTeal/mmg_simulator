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
include include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/depend.make

# Include the progress variables for this target.
include include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/progress.make

# Include the compile flags for this target's objects.
include include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/flags.make

include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/compile_MatrixBase_diagonal.cpp.o: include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/flags.make
include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/compile_MatrixBase_diagonal.cpp.o: include/eigen/doc/snippets/compile_MatrixBase_diagonal.cpp
include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/compile_MatrixBase_diagonal.cpp.o: ../include/eigen/doc/snippets/MatrixBase_diagonal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/compile_MatrixBase_diagonal.cpp.o"
	cd /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build/include/eigen/doc/snippets && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compile_MatrixBase_diagonal.dir/compile_MatrixBase_diagonal.cpp.o -c /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build/include/eigen/doc/snippets/compile_MatrixBase_diagonal.cpp

include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/compile_MatrixBase_diagonal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compile_MatrixBase_diagonal.dir/compile_MatrixBase_diagonal.cpp.i"
	cd /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build/include/eigen/doc/snippets && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build/include/eigen/doc/snippets/compile_MatrixBase_diagonal.cpp > CMakeFiles/compile_MatrixBase_diagonal.dir/compile_MatrixBase_diagonal.cpp.i

include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/compile_MatrixBase_diagonal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compile_MatrixBase_diagonal.dir/compile_MatrixBase_diagonal.cpp.s"
	cd /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build/include/eigen/doc/snippets && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build/include/eigen/doc/snippets/compile_MatrixBase_diagonal.cpp -o CMakeFiles/compile_MatrixBase_diagonal.dir/compile_MatrixBase_diagonal.cpp.s

include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/compile_MatrixBase_diagonal.cpp.o.requires:

.PHONY : include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/compile_MatrixBase_diagonal.cpp.o.requires

include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/compile_MatrixBase_diagonal.cpp.o.provides: include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/compile_MatrixBase_diagonal.cpp.o.requires
	$(MAKE) -f include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/build.make include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/compile_MatrixBase_diagonal.cpp.o.provides.build
.PHONY : include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/compile_MatrixBase_diagonal.cpp.o.provides

include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/compile_MatrixBase_diagonal.cpp.o.provides.build: include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/compile_MatrixBase_diagonal.cpp.o


# Object files for target compile_MatrixBase_diagonal
compile_MatrixBase_diagonal_OBJECTS = \
"CMakeFiles/compile_MatrixBase_diagonal.dir/compile_MatrixBase_diagonal.cpp.o"

# External object files for target compile_MatrixBase_diagonal
compile_MatrixBase_diagonal_EXTERNAL_OBJECTS =

include/eigen/doc/snippets/compile_MatrixBase_diagonal: include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/compile_MatrixBase_diagonal.cpp.o
include/eigen/doc/snippets/compile_MatrixBase_diagonal: include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/build.make
include/eigen/doc/snippets/compile_MatrixBase_diagonal: include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable compile_MatrixBase_diagonal"
	cd /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build/include/eigen/doc/snippets && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/compile_MatrixBase_diagonal.dir/link.txt --verbose=$(VERBOSE)
	cd /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build/include/eigen/doc/snippets && ./compile_MatrixBase_diagonal >/home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build/include/eigen/doc/snippets/MatrixBase_diagonal.out

# Rule to build all files generated by this target.
include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/build: include/eigen/doc/snippets/compile_MatrixBase_diagonal

.PHONY : include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/build

include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/requires: include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/compile_MatrixBase_diagonal.cpp.o.requires

.PHONY : include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/requires

include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/clean:
	cd /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build/include/eigen/doc/snippets && $(CMAKE_COMMAND) -P CMakeFiles/compile_MatrixBase_diagonal.dir/cmake_clean.cmake
.PHONY : include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/clean

include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/depend:
	cd /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/include/eigen/doc/snippets /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build/include/eigen/doc/snippets /home/suisei/windata1/projects/research/doctor/projects/mmg_simulator/build/include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : include/eigen/doc/snippets/CMakeFiles/compile_MatrixBase_diagonal.dir/depend
