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
include CMakeFiles/1556.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/1556.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1556.dir/flags.make

CMakeFiles/1556.dir/Chapter2_List/OJ/1-1.c.obj: CMakeFiles/1556.dir/flags.make
CMakeFiles/1556.dir/Chapter2_List/OJ/1-1.c.obj: ../Chapter2_List/OJ/1-1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\GitHub\DataStructures\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/1556.dir/Chapter2_List/OJ/1-1.c.obj"
	C:\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\1556.dir\Chapter2_List\OJ\1-1.c.obj   -c C:\GitHub\DataStructures\Chapter2_List\OJ\1-1.c

CMakeFiles/1556.dir/Chapter2_List/OJ/1-1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/1556.dir/Chapter2_List/OJ/1-1.c.i"
	C:\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\GitHub\DataStructures\Chapter2_List\OJ\1-1.c > CMakeFiles\1556.dir\Chapter2_List\OJ\1-1.c.i

CMakeFiles/1556.dir/Chapter2_List/OJ/1-1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/1556.dir/Chapter2_List/OJ/1-1.c.s"
	C:\mingw\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\GitHub\DataStructures\Chapter2_List\OJ\1-1.c -o CMakeFiles\1556.dir\Chapter2_List\OJ\1-1.c.s

# Object files for target 1556
1556_OBJECTS = \
"CMakeFiles/1556.dir/Chapter2_List/OJ/1-1.c.obj"

# External object files for target 1556
1556_EXTERNAL_OBJECTS =

1556.exe: CMakeFiles/1556.dir/Chapter2_List/OJ/1-1.c.obj
1556.exe: CMakeFiles/1556.dir/build.make
1556.exe: CMakeFiles/1556.dir/linklibs.rsp
1556.exe: CMakeFiles/1556.dir/objects1.rsp
1556.exe: CMakeFiles/1556.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\GitHub\DataStructures\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 1556.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\1556.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1556.dir/build: 1556.exe

.PHONY : CMakeFiles/1556.dir/build

CMakeFiles/1556.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\1556.dir\cmake_clean.cmake
.PHONY : CMakeFiles/1556.dir/clean

CMakeFiles/1556.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\GitHub\DataStructures C:\GitHub\DataStructures C:\GitHub\DataStructures\cmake-build-debug C:\GitHub\DataStructures\cmake-build-debug C:\GitHub\DataStructures\cmake-build-debug\CMakeFiles\1556.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/1556.dir/depend

