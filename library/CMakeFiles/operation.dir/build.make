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
CMAKE_SOURCE_DIR = /home/enzo/travail/c/operation_function

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/enzo/travail/c/operation_function/library

# Include any dependencies generated for this target.
include CMakeFiles/operation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/operation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/operation.dir/flags.make

CMakeFiles/operation.dir/op_text.c.o: CMakeFiles/operation.dir/flags.make
CMakeFiles/operation.dir/op_text.c.o: ../op_text.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/enzo/travail/c/operation_function/library/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/operation.dir/op_text.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/operation.dir/op_text.c.o   -c /home/enzo/travail/c/operation_function/op_text.c

CMakeFiles/operation.dir/op_text.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/operation.dir/op_text.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/enzo/travail/c/operation_function/op_text.c > CMakeFiles/operation.dir/op_text.c.i

CMakeFiles/operation.dir/op_text.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/operation.dir/op_text.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/enzo/travail/c/operation_function/op_text.c -o CMakeFiles/operation.dir/op_text.c.s

# Object files for target operation
operation_OBJECTS = \
"CMakeFiles/operation.dir/op_text.c.o"

# External object files for target operation
operation_EXTERNAL_OBJECTS =

operation: CMakeFiles/operation.dir/op_text.c.o
operation: CMakeFiles/operation.dir/build.make
operation: libop.a
operation: CMakeFiles/operation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/enzo/travail/c/operation_function/library/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable operation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/operation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/operation.dir/build: operation

.PHONY : CMakeFiles/operation.dir/build

CMakeFiles/operation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/operation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/operation.dir/clean

CMakeFiles/operation.dir/depend:
	cd /home/enzo/travail/c/operation_function/library && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/enzo/travail/c/operation_function /home/enzo/travail/c/operation_function /home/enzo/travail/c/operation_function/library /home/enzo/travail/c/operation_function/library /home/enzo/travail/c/operation_function/library/CMakeFiles/operation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/operation.dir/depend

