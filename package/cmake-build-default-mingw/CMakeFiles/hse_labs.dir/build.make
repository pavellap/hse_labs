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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\pavellap\CLionProjects\hse_labs\package

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\pavellap\CLionProjects\hse_labs\package\cmake-build-default-mingw

# Include any dependencies generated for this target.
include CMakeFiles/hse_labs.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hse_labs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hse_labs.dir/flags.make

CMakeFiles/hse_labs.dir/utils.cpp.obj: CMakeFiles/hse_labs.dir/flags.make
CMakeFiles/hse_labs.dir/utils.cpp.obj: ../utils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pavellap\CLionProjects\hse_labs\package\cmake-build-default-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hse_labs.dir/utils.cpp.obj"
	C:\Compilers\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\hse_labs.dir\utils.cpp.obj -c C:\Users\pavellap\CLionProjects\hse_labs\package\utils.cpp

CMakeFiles/hse_labs.dir/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hse_labs.dir/utils.cpp.i"
	C:\Compilers\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\pavellap\CLionProjects\hse_labs\package\utils.cpp > CMakeFiles\hse_labs.dir\utils.cpp.i

CMakeFiles/hse_labs.dir/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hse_labs.dir/utils.cpp.s"
	C:\Compilers\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\pavellap\CLionProjects\hse_labs\package\utils.cpp -o CMakeFiles\hse_labs.dir\utils.cpp.s

CMakeFiles/hse_labs.dir/5.lambda.cpp.obj: CMakeFiles/hse_labs.dir/flags.make
CMakeFiles/hse_labs.dir/5.lambda.cpp.obj: ../5.lambda.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\pavellap\CLionProjects\hse_labs\package\cmake-build-default-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/hse_labs.dir/5.lambda.cpp.obj"
	C:\Compilers\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\hse_labs.dir\5.lambda.cpp.obj -c C:\Users\pavellap\CLionProjects\hse_labs\package\5.lambda.cpp

CMakeFiles/hse_labs.dir/5.lambda.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hse_labs.dir/5.lambda.cpp.i"
	C:\Compilers\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\pavellap\CLionProjects\hse_labs\package\5.lambda.cpp > CMakeFiles\hse_labs.dir\5.lambda.cpp.i

CMakeFiles/hse_labs.dir/5.lambda.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hse_labs.dir/5.lambda.cpp.s"
	C:\Compilers\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\pavellap\CLionProjects\hse_labs\package\5.lambda.cpp -o CMakeFiles\hse_labs.dir\5.lambda.cpp.s

# Object files for target hse_labs
hse_labs_OBJECTS = \
"CMakeFiles/hse_labs.dir/utils.cpp.obj" \
"CMakeFiles/hse_labs.dir/5.lambda.cpp.obj"

# External object files for target hse_labs
hse_labs_EXTERNAL_OBJECTS =

hse_labs.exe: CMakeFiles/hse_labs.dir/utils.cpp.obj
hse_labs.exe: CMakeFiles/hse_labs.dir/5.lambda.cpp.obj
hse_labs.exe: CMakeFiles/hse_labs.dir/build.make
hse_labs.exe: CMakeFiles/hse_labs.dir/linklibs.rsp
hse_labs.exe: CMakeFiles/hse_labs.dir/objects1.rsp
hse_labs.exe: CMakeFiles/hse_labs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\pavellap\CLionProjects\hse_labs\package\cmake-build-default-mingw\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable hse_labs.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\hse_labs.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hse_labs.dir/build: hse_labs.exe

.PHONY : CMakeFiles/hse_labs.dir/build

CMakeFiles/hse_labs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\hse_labs.dir\cmake_clean.cmake
.PHONY : CMakeFiles/hse_labs.dir/clean

CMakeFiles/hse_labs.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\pavellap\CLionProjects\hse_labs\package C:\Users\pavellap\CLionProjects\hse_labs\package C:\Users\pavellap\CLionProjects\hse_labs\package\cmake-build-default-mingw C:\Users\pavellap\CLionProjects\hse_labs\package\cmake-build-default-mingw C:\Users\pavellap\CLionProjects\hse_labs\package\cmake-build-default-mingw\CMakeFiles\hse_labs.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hse_labs.dir/depend
