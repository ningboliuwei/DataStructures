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
include CMakeFiles/20181127_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/20181127_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/20181127_2.dir/flags.make

CMakeFiles/20181127_2.dir/StudentWorks/20181127_2.cpp.obj: CMakeFiles/20181127_2.dir/flags.make
CMakeFiles/20181127_2.dir/StudentWorks/20181127_2.cpp.obj: ../StudentWorks/20181127_2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\GitHub\DataStructures\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/20181127_2.dir/StudentWorks/20181127_2.cpp.obj"
	C:\mingw\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\20181127_2.dir\StudentWorks\20181127_2.cpp.obj -c C:\GitHub\DataStructures\StudentWorks\20181127_2.cpp

CMakeFiles/20181127_2.dir/StudentWorks/20181127_2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/20181127_2.dir/StudentWorks/20181127_2.cpp.i"
	C:\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\GitHub\DataStructures\StudentWorks\20181127_2.cpp > CMakeFiles\20181127_2.dir\StudentWorks\20181127_2.cpp.i

CMakeFiles/20181127_2.dir/StudentWorks/20181127_2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/20181127_2.dir/StudentWorks/20181127_2.cpp.s"
	C:\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\GitHub\DataStructures\StudentWorks\20181127_2.cpp -o CMakeFiles\20181127_2.dir\StudentWorks\20181127_2.cpp.s

# Object files for target 20181127_2
20181127_2_OBJECTS = \
"CMakeFiles/20181127_2.dir/StudentWorks/20181127_2.cpp.obj"

# External object files for target 20181127_2
20181127_2_EXTERNAL_OBJECTS =

20181127_2.exe: CMakeFiles/20181127_2.dir/StudentWorks/20181127_2.cpp.obj
20181127_2.exe: CMakeFiles/20181127_2.dir/build.make
20181127_2.exe: CMakeFiles/20181127_2.dir/linklibs.rsp
20181127_2.exe: CMakeFiles/20181127_2.dir/objects1.rsp
20181127_2.exe: CMakeFiles/20181127_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\GitHub\DataStructures\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 20181127_2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\20181127_2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/20181127_2.dir/build: 20181127_2.exe

.PHONY : CMakeFiles/20181127_2.dir/build

CMakeFiles/20181127_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\20181127_2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/20181127_2.dir/clean

CMakeFiles/20181127_2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\GitHub\DataStructures C:\GitHub\DataStructures C:\GitHub\DataStructures\cmake-build-debug C:\GitHub\DataStructures\cmake-build-debug C:\GitHub\DataStructures\cmake-build-debug\CMakeFiles\20181127_2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/20181127_2.dir/depend

