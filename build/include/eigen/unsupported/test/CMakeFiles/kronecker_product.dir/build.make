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

# Utility rule file for kronecker_product.

# Include the progress variables for this target.
include include/eigen/unsupported/test/CMakeFiles/kronecker_product.dir/progress.make

kronecker_product: include/eigen/unsupported/test/CMakeFiles/kronecker_product.dir/build.make

.PHONY : kronecker_product

# Rule to build all files generated by this target.
include/eigen/unsupported/test/CMakeFiles/kronecker_product.dir/build: kronecker_product

.PHONY : include/eigen/unsupported/test/CMakeFiles/kronecker_product.dir/build

include/eigen/unsupported/test/CMakeFiles/kronecker_product.dir/clean:
	cd /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build/include/eigen/unsupported/test && $(CMAKE_COMMAND) -P CMakeFiles/kronecker_product.dir/cmake_clean.cmake
.PHONY : include/eigen/unsupported/test/CMakeFiles/kronecker_product.dir/clean

include/eigen/unsupported/test/CMakeFiles/kronecker_product.dir/depend:
	cd /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/suisei/windata/projects/research/doctor/projects/mmg_simulator /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/include/eigen/unsupported/test /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build/include/eigen/unsupported/test /home/suisei/windata/projects/research/doctor/projects/mmg_simulator/build/include/eigen/unsupported/test/CMakeFiles/kronecker_product.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : include/eigen/unsupported/test/CMakeFiles/kronecker_product.dir/depend

