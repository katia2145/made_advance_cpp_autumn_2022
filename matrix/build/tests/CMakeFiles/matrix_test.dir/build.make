# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/code/made_advance_cpp_autumn_2022/matrix

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/code/made_advance_cpp_autumn_2022/matrix/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/matrix_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/matrix_test.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/matrix_test.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/matrix_test.dir/flags.make

tests/CMakeFiles/matrix_test.dir/test_matrix.cpp.o: tests/CMakeFiles/matrix_test.dir/flags.make
tests/CMakeFiles/matrix_test.dir/test_matrix.cpp.o: ../tests/test_matrix.cpp
tests/CMakeFiles/matrix_test.dir/test_matrix.cpp.o: tests/CMakeFiles/matrix_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/code/made_advance_cpp_autumn_2022/matrix/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/matrix_test.dir/test_matrix.cpp.o"
	cd /home/code/made_advance_cpp_autumn_2022/matrix/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/matrix_test.dir/test_matrix.cpp.o -MF CMakeFiles/matrix_test.dir/test_matrix.cpp.o.d -o CMakeFiles/matrix_test.dir/test_matrix.cpp.o -c /home/code/made_advance_cpp_autumn_2022/matrix/tests/test_matrix.cpp

tests/CMakeFiles/matrix_test.dir/test_matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/matrix_test.dir/test_matrix.cpp.i"
	cd /home/code/made_advance_cpp_autumn_2022/matrix/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/code/made_advance_cpp_autumn_2022/matrix/tests/test_matrix.cpp > CMakeFiles/matrix_test.dir/test_matrix.cpp.i

tests/CMakeFiles/matrix_test.dir/test_matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/matrix_test.dir/test_matrix.cpp.s"
	cd /home/code/made_advance_cpp_autumn_2022/matrix/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/code/made_advance_cpp_autumn_2022/matrix/tests/test_matrix.cpp -o CMakeFiles/matrix_test.dir/test_matrix.cpp.s

# Object files for target matrix_test
matrix_test_OBJECTS = \
"CMakeFiles/matrix_test.dir/test_matrix.cpp.o"

# External object files for target matrix_test
matrix_test_EXTERNAL_OBJECTS =

tests/matrix_test: tests/CMakeFiles/matrix_test.dir/test_matrix.cpp.o
tests/matrix_test: tests/CMakeFiles/matrix_test.dir/build.make
tests/matrix_test: matrix_lib/libmatrix_lib.a
tests/matrix_test: /usr/lib/x86_64-linux-gnu/libgtest_main.a
tests/matrix_test: /usr/lib/x86_64-linux-gnu/libgtest.a
tests/matrix_test: tests/CMakeFiles/matrix_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/code/made_advance_cpp_autumn_2022/matrix/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable matrix_test"
	cd /home/code/made_advance_cpp_autumn_2022/matrix/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/matrix_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/matrix_test.dir/build: tests/matrix_test
.PHONY : tests/CMakeFiles/matrix_test.dir/build

tests/CMakeFiles/matrix_test.dir/clean:
	cd /home/code/made_advance_cpp_autumn_2022/matrix/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/matrix_test.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/matrix_test.dir/clean

tests/CMakeFiles/matrix_test.dir/depend:
	cd /home/code/made_advance_cpp_autumn_2022/matrix/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/code/made_advance_cpp_autumn_2022/matrix /home/code/made_advance_cpp_autumn_2022/matrix/tests /home/code/made_advance_cpp_autumn_2022/matrix/build /home/code/made_advance_cpp_autumn_2022/matrix/build/tests /home/code/made_advance_cpp_autumn_2022/matrix/build/tests/CMakeFiles/matrix_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/matrix_test.dir/depend

