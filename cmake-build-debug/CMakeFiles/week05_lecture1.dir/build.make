# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Users\Liu Wei\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\201.6668.126\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Users\Liu Wei\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\201.6668.126\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\GitHub\DataStructures

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\GitHub\DataStructures\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/week05_lecture1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/week05_lecture1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/week05_lecture1.dir/flags.make

CMakeFiles/week05_lecture1.dir/LECTURES&LABS/Week05_LECTURE_DEMO/LinkListWithoutHeadNode.c.obj: CMakeFiles/week05_lecture1.dir/flags.make
CMakeFiles/week05_lecture1.dir/LECTURES&LABS/Week05_LECTURE_DEMO/LinkListWithoutHeadNode.c.obj: ../LECTURES&LABS/Week05_LECTURE_DEMO/LinkListWithoutHeadNode.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\GitHub\DataStructures\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/week05_lecture1.dir/LECTURES&LABS/Week05_LECTURE_DEMO/LinkListWithoutHeadNode.c.obj"
	C:\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o "CMakeFiles\week05_lecture1.dir\LECTURES&LABS\Week05_LECTURE_DEMO\LinkListWithoutHeadNode.c.obj"   -c "C:\GitHub\DataStructures\LECTURES&LABS\Week05_LECTURE_DEMO\LinkListWithoutHeadNode.c"

CMakeFiles/week05_lecture1.dir/LECTURES&LABS/Week05_LECTURE_DEMO/LinkListWithoutHeadNode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/week05_lecture1.dir/LECTURES&LABS/Week05_LECTURE_DEMO/LinkListWithoutHeadNode.c.i"
	C:\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\GitHub\DataStructures\LECTURES&LABS\Week05_LECTURE_DEMO\LinkListWithoutHeadNode.c" > "CMakeFiles\week05_lecture1.dir\LECTURES&LABS\Week05_LECTURE_DEMO\LinkListWithoutHeadNode.c.i"

CMakeFiles/week05_lecture1.dir/LECTURES&LABS/Week05_LECTURE_DEMO/LinkListWithoutHeadNode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/week05_lecture1.dir/LECTURES&LABS/Week05_LECTURE_DEMO/LinkListWithoutHeadNode.c.s"
	C:\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\GitHub\DataStructures\LECTURES&LABS\Week05_LECTURE_DEMO\LinkListWithoutHeadNode.c" -o "CMakeFiles\week05_lecture1.dir\LECTURES&LABS\Week05_LECTURE_DEMO\LinkListWithoutHeadNode.c.s"

# Object files for target week05_lecture1
week05_lecture1_OBJECTS = \
"CMakeFiles/week05_lecture1.dir/LECTURES&LABS/Week05_LECTURE_DEMO/LinkListWithoutHeadNode.c.obj"

# External object files for target week05_lecture1
week05_lecture1_EXTERNAL_OBJECTS =

week05_lecture1.exe: CMakeFiles/week05_lecture1.dir/LECTURES&LABS/Week05_LECTURE_DEMO/LinkListWithoutHeadNode.c.obj
week05_lecture1.exe: CMakeFiles/week05_lecture1.dir/build.make
week05_lecture1.exe: CMakeFiles/week05_lecture1.dir/linklibs.rsp
week05_lecture1.exe: CMakeFiles/week05_lecture1.dir/objects1.rsp
week05_lecture1.exe: CMakeFiles/week05_lecture1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\GitHub\DataStructures\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable week05_lecture1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\week05_lecture1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/week05_lecture1.dir/build: week05_lecture1.exe

.PHONY : CMakeFiles/week05_lecture1.dir/build

CMakeFiles/week05_lecture1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\week05_lecture1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/week05_lecture1.dir/clean

CMakeFiles/week05_lecture1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\GitHub\DataStructures C:\GitHub\DataStructures C:\GitHub\DataStructures\cmake-build-debug C:\GitHub\DataStructures\cmake-build-debug C:\GitHub\DataStructures\cmake-build-debug\CMakeFiles\week05_lecture1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/week05_lecture1.dir/depend
