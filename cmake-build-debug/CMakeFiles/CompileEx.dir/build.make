# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\Toolbox\apps\CLion\ch-0\211.7142.21\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\Toolbox\apps\CLion\ch-0\211.7142.21\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\WorkSpace\CLionProjects\CompileEx

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\WorkSpace\CLionProjects\CompileEx\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CompileEx.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CompileEx.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CompileEx.dir/flags.make

CMakeFiles/CompileEx.dir/main.cpp.obj: CMakeFiles/CompileEx.dir/flags.make
CMakeFiles/CompileEx.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\WorkSpace\CLionProjects\CompileEx\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CompileEx.dir/main.cpp.obj"
	D:\Path\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CompileEx.dir\main.cpp.obj -c D:\WorkSpace\CLionProjects\CompileEx\main.cpp

CMakeFiles/CompileEx.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CompileEx.dir/main.cpp.i"
	D:\Path\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\WorkSpace\CLionProjects\CompileEx\main.cpp > CMakeFiles\CompileEx.dir\main.cpp.i

CMakeFiles/CompileEx.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CompileEx.dir/main.cpp.s"
	D:\Path\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\WorkSpace\CLionProjects\CompileEx\main.cpp -o CMakeFiles\CompileEx.dir\main.cpp.s

CMakeFiles/CompileEx.dir/source/Ex2.cpp.obj: CMakeFiles/CompileEx.dir/flags.make
CMakeFiles/CompileEx.dir/source/Ex2.cpp.obj: ../source/Ex2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\WorkSpace\CLionProjects\CompileEx\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CompileEx.dir/source/Ex2.cpp.obj"
	D:\Path\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CompileEx.dir\source\Ex2.cpp.obj -c D:\WorkSpace\CLionProjects\CompileEx\source\Ex2.cpp

CMakeFiles/CompileEx.dir/source/Ex2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CompileEx.dir/source/Ex2.cpp.i"
	D:\Path\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\WorkSpace\CLionProjects\CompileEx\source\Ex2.cpp > CMakeFiles\CompileEx.dir\source\Ex2.cpp.i

CMakeFiles/CompileEx.dir/source/Ex2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CompileEx.dir/source/Ex2.cpp.s"
	D:\Path\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\WorkSpace\CLionProjects\CompileEx\source\Ex2.cpp -o CMakeFiles\CompileEx.dir\source\Ex2.cpp.s

# Object files for target CompileEx
CompileEx_OBJECTS = \
"CMakeFiles/CompileEx.dir/main.cpp.obj" \
"CMakeFiles/CompileEx.dir/source/Ex2.cpp.obj"

# External object files for target CompileEx
CompileEx_EXTERNAL_OBJECTS =

CompileEx.exe: CMakeFiles/CompileEx.dir/main.cpp.obj
CompileEx.exe: CMakeFiles/CompileEx.dir/source/Ex2.cpp.obj
CompileEx.exe: CMakeFiles/CompileEx.dir/build.make
CompileEx.exe: CMakeFiles/CompileEx.dir/linklibs.rsp
CompileEx.exe: CMakeFiles/CompileEx.dir/objects1.rsp
CompileEx.exe: CMakeFiles/CompileEx.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\WorkSpace\CLionProjects\CompileEx\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable CompileEx.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CompileEx.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CompileEx.dir/build: CompileEx.exe

.PHONY : CMakeFiles/CompileEx.dir/build

CMakeFiles/CompileEx.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CompileEx.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CompileEx.dir/clean

CMakeFiles/CompileEx.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\WorkSpace\CLionProjects\CompileEx D:\WorkSpace\CLionProjects\CompileEx D:\WorkSpace\CLionProjects\CompileEx\cmake-build-debug D:\WorkSpace\CLionProjects\CompileEx\cmake-build-debug D:\WorkSpace\CLionProjects\CompileEx\cmake-build-debug\CMakeFiles\CompileEx.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CompileEx.dir/depend
