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
include CMakeFiles/TraverseTree_Link.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TraverseTree_Link.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TraverseTree_Link.dir/flags.make

CMakeFiles/TraverseTree_Link.dir/Chapter7_Tree/TraverseTree/TraverseTree_Link.cpp.obj: CMakeFiles/TraverseTree_Link.dir/flags.make
CMakeFiles/TraverseTree_Link.dir/Chapter7_Tree/TraverseTree/TraverseTree_Link.cpp.obj: ../Chapter7_Tree/TraverseTree/TraverseTree_Link.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\GitHub\DataStructures\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TraverseTree_Link.dir/Chapter7_Tree/TraverseTree/TraverseTree_Link.cpp.obj"
	C:\mingw\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\TraverseTree_Link.dir\Chapter7_Tree\TraverseTree\TraverseTree_Link.cpp.obj -c C:\GitHub\DataStructures\Chapter7_Tree\TraverseTree\TraverseTree_Link.cpp

CMakeFiles/TraverseTree_Link.dir/Chapter7_Tree/TraverseTree/TraverseTree_Link.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TraverseTree_Link.dir/Chapter7_Tree/TraverseTree/TraverseTree_Link.cpp.i"
	C:\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\GitHub\DataStructures\Chapter7_Tree\TraverseTree\TraverseTree_Link.cpp > CMakeFiles\TraverseTree_Link.dir\Chapter7_Tree\TraverseTree\TraverseTree_Link.cpp.i

CMakeFiles/TraverseTree_Link.dir/Chapter7_Tree/TraverseTree/TraverseTree_Link.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TraverseTree_Link.dir/Chapter7_Tree/TraverseTree/TraverseTree_Link.cpp.s"
	C:\mingw\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\GitHub\DataStructures\Chapter7_Tree\TraverseTree\TraverseTree_Link.cpp -o CMakeFiles\TraverseTree_Link.dir\Chapter7_Tree\TraverseTree\TraverseTree_Link.cpp.s

# Object files for target TraverseTree_Link
TraverseTree_Link_OBJECTS = \
"CMakeFiles/TraverseTree_Link.dir/Chapter7_Tree/TraverseTree/TraverseTree_Link.cpp.obj"

# External object files for target TraverseTree_Link
TraverseTree_Link_EXTERNAL_OBJECTS =

TraverseTree_Link.exe: CMakeFiles/TraverseTree_Link.dir/Chapter7_Tree/TraverseTree/TraverseTree_Link.cpp.obj
TraverseTree_Link.exe: CMakeFiles/TraverseTree_Link.dir/build.make
TraverseTree_Link.exe: CMakeFiles/TraverseTree_Link.dir/linklibs.rsp
TraverseTree_Link.exe: CMakeFiles/TraverseTree_Link.dir/objects1.rsp
TraverseTree_Link.exe: CMakeFiles/TraverseTree_Link.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\GitHub\DataStructures\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TraverseTree_Link.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TraverseTree_Link.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TraverseTree_Link.dir/build: TraverseTree_Link.exe

.PHONY : CMakeFiles/TraverseTree_Link.dir/build

CMakeFiles/TraverseTree_Link.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TraverseTree_Link.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TraverseTree_Link.dir/clean

CMakeFiles/TraverseTree_Link.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\GitHub\DataStructures C:\GitHub\DataStructures C:\GitHub\DataStructures\cmake-build-debug C:\GitHub\DataStructures\cmake-build-debug C:\GitHub\DataStructures\cmake-build-debug\CMakeFiles\TraverseTree_Link.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TraverseTree_Link.dir/depend
