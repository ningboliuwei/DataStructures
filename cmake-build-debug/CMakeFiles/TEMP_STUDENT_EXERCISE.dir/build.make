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
include CMakeFiles/TEMP_STUDENT_EXERCISE.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TEMP_STUDENT_EXERCISE.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TEMP_STUDENT_EXERCISE.dir/flags.make

CMakeFiles/TEMP_STUDENT_EXERCISE.dir/TEMP/TEMP_STUDENT_EXERCISE.cpp.obj: CMakeFiles/TEMP_STUDENT_EXERCISE.dir/flags.make
CMakeFiles/TEMP_STUDENT_EXERCISE.dir/TEMP/TEMP_STUDENT_EXERCISE.cpp.obj: ../TEMP/TEMP_STUDENT_EXERCISE.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\GitHub\DataStructures\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TEMP_STUDENT_EXERCISE.dir/TEMP/TEMP_STUDENT_EXERCISE.cpp.obj"
	C:\mingw\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\TEMP_STUDENT_EXERCISE.dir\TEMP\TEMP_STUDENT_EXERCISE.cpp.obj -c C:\GitHub\DataStructures\TEMP\TEMP_STUDENT_EXERCISE.cpp

CMakeFiles/TEMP_STUDENT_EXERCISE.dir/TEMP/TEMP_STUDENT_EXERCISE.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TEMP_STUDENT_EXERCISE.dir/TEMP/TEMP_STUDENT_EXERCISE.cpp.i"
	C:\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\GitHub\DataStructures\TEMP\TEMP_STUDENT_EXERCISE.cpp > CMakeFiles\TEMP_STUDENT_EXERCISE.dir\TEMP\TEMP_STUDENT_EXERCISE.cpp.i

CMakeFiles/TEMP_STUDENT_EXERCISE.dir/TEMP/TEMP_STUDENT_EXERCISE.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TEMP_STUDENT_EXERCISE.dir/TEMP/TEMP_STUDENT_EXERCISE.cpp.s"
	C:\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\GitHub\DataStructures\TEMP\TEMP_STUDENT_EXERCISE.cpp -o CMakeFiles\TEMP_STUDENT_EXERCISE.dir\TEMP\TEMP_STUDENT_EXERCISE.cpp.s

# Object files for target TEMP_STUDENT_EXERCISE
TEMP_STUDENT_EXERCISE_OBJECTS = \
"CMakeFiles/TEMP_STUDENT_EXERCISE.dir/TEMP/TEMP_STUDENT_EXERCISE.cpp.obj"

# External object files for target TEMP_STUDENT_EXERCISE
TEMP_STUDENT_EXERCISE_EXTERNAL_OBJECTS =

TEMP_STUDENT_EXERCISE.exe: CMakeFiles/TEMP_STUDENT_EXERCISE.dir/TEMP/TEMP_STUDENT_EXERCISE.cpp.obj
TEMP_STUDENT_EXERCISE.exe: CMakeFiles/TEMP_STUDENT_EXERCISE.dir/build.make
TEMP_STUDENT_EXERCISE.exe: CMakeFiles/TEMP_STUDENT_EXERCISE.dir/linklibs.rsp
TEMP_STUDENT_EXERCISE.exe: CMakeFiles/TEMP_STUDENT_EXERCISE.dir/objects1.rsp
TEMP_STUDENT_EXERCISE.exe: CMakeFiles/TEMP_STUDENT_EXERCISE.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\GitHub\DataStructures\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TEMP_STUDENT_EXERCISE.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TEMP_STUDENT_EXERCISE.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TEMP_STUDENT_EXERCISE.dir/build: TEMP_STUDENT_EXERCISE.exe

.PHONY : CMakeFiles/TEMP_STUDENT_EXERCISE.dir/build

CMakeFiles/TEMP_STUDENT_EXERCISE.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TEMP_STUDENT_EXERCISE.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TEMP_STUDENT_EXERCISE.dir/clean

CMakeFiles/TEMP_STUDENT_EXERCISE.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\GitHub\DataStructures C:\GitHub\DataStructures C:\GitHub\DataStructures\cmake-build-debug C:\GitHub\DataStructures\cmake-build-debug C:\GitHub\DataStructures\cmake-build-debug\CMakeFiles\TEMP_STUDENT_EXERCISE.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TEMP_STUDENT_EXERCISE.dir/depend
