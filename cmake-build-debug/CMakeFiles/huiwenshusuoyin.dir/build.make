# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\_002.Clion\CLion-2020.3.3.win\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = D:\_002.Clion\CLion-2020.3.3.win\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\_08.Clion

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\_08.Clion\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/huiwenshusuoyin.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/huiwenshusuoyin.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/huiwenshusuoyin.dir/flags.make

CMakeFiles/huiwenshusuoyin.dir/WY/huiwenshusuoyin.cpp.obj: CMakeFiles/huiwenshusuoyin.dir/flags.make
CMakeFiles/huiwenshusuoyin.dir/WY/huiwenshusuoyin.cpp.obj: ../WY/huiwenshusuoyin.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\_08.Clion\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/huiwenshusuoyin.dir/WY/huiwenshusuoyin.cpp.obj"
	D:\_01.Software\_02.VsCode\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\huiwenshusuoyin.dir\WY\huiwenshusuoyin.cpp.obj -c D:\_08.Clion\WY\huiwenshusuoyin.cpp

CMakeFiles/huiwenshusuoyin.dir/WY/huiwenshusuoyin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/huiwenshusuoyin.dir/WY/huiwenshusuoyin.cpp.i"
	D:\_01.Software\_02.VsCode\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\_08.Clion\WY\huiwenshusuoyin.cpp > CMakeFiles\huiwenshusuoyin.dir\WY\huiwenshusuoyin.cpp.i

CMakeFiles/huiwenshusuoyin.dir/WY/huiwenshusuoyin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/huiwenshusuoyin.dir/WY/huiwenshusuoyin.cpp.s"
	D:\_01.Software\_02.VsCode\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\_08.Clion\WY\huiwenshusuoyin.cpp -o CMakeFiles\huiwenshusuoyin.dir\WY\huiwenshusuoyin.cpp.s

# Object files for target huiwenshusuoyin
huiwenshusuoyin_OBJECTS = \
"CMakeFiles/huiwenshusuoyin.dir/WY/huiwenshusuoyin.cpp.obj"

# External object files for target huiwenshusuoyin
huiwenshusuoyin_EXTERNAL_OBJECTS =

huiwenshusuoyin.exe: CMakeFiles/huiwenshusuoyin.dir/WY/huiwenshusuoyin.cpp.obj
huiwenshusuoyin.exe: CMakeFiles/huiwenshusuoyin.dir/build.make
huiwenshusuoyin.exe: CMakeFiles/huiwenshusuoyin.dir/linklibs.rsp
huiwenshusuoyin.exe: CMakeFiles/huiwenshusuoyin.dir/objects1.rsp
huiwenshusuoyin.exe: CMakeFiles/huiwenshusuoyin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\_08.Clion\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable huiwenshusuoyin.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\huiwenshusuoyin.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/huiwenshusuoyin.dir/build: huiwenshusuoyin.exe

.PHONY : CMakeFiles/huiwenshusuoyin.dir/build

CMakeFiles/huiwenshusuoyin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\huiwenshusuoyin.dir\cmake_clean.cmake
.PHONY : CMakeFiles/huiwenshusuoyin.dir/clean

CMakeFiles/huiwenshusuoyin.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\_08.Clion D:\_08.Clion D:\_08.Clion\cmake-build-debug D:\_08.Clion\cmake-build-debug D:\_08.Clion\cmake-build-debug\CMakeFiles\huiwenshusuoyin.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/huiwenshusuoyin.dir/depend

