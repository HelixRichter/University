# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = C:\Users\AlexK-PC\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.5744.254\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\AlexK-PC\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\213.5744.254\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\CLionProjectFolder\LabWork 1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\CLionProjectFolder\LabWork 1\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/LabWork_1.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/LabWork_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LabWork_1.dir/flags.make

CMakeFiles/LabWork_1.dir/main.c.obj: CMakeFiles/LabWork_1.dir/flags.make
CMakeFiles/LabWork_1.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\CLionProjectFolder\LabWork 1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/LabWork_1.dir/main.c.obj"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\LabWork_1.dir\main.c.obj -c "D:\CLionProjectFolder\LabWork 1\main.c"

CMakeFiles/LabWork_1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LabWork_1.dir/main.c.i"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\CLionProjectFolder\LabWork 1\main.c" > CMakeFiles\LabWork_1.dir\main.c.i

CMakeFiles/LabWork_1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LabWork_1.dir/main.c.s"
	D:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\CLionProjectFolder\LabWork 1\main.c" -o CMakeFiles\LabWork_1.dir\main.c.s

# Object files for target LabWork_1
LabWork_1_OBJECTS = \
"CMakeFiles/LabWork_1.dir/main.c.obj"

# External object files for target LabWork_1
LabWork_1_EXTERNAL_OBJECTS =

LabWork_1.exe: CMakeFiles/LabWork_1.dir/main.c.obj
LabWork_1.exe: CMakeFiles/LabWork_1.dir/build.make
LabWork_1.exe: CMakeFiles/LabWork_1.dir/linklibs.rsp
LabWork_1.exe: CMakeFiles/LabWork_1.dir/objects1.rsp
LabWork_1.exe: CMakeFiles/LabWork_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\CLionProjectFolder\LabWork 1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable LabWork_1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\LabWork_1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LabWork_1.dir/build: LabWork_1.exe
.PHONY : CMakeFiles/LabWork_1.dir/build

CMakeFiles/LabWork_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\LabWork_1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/LabWork_1.dir/clean

CMakeFiles/LabWork_1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\CLionProjectFolder\LabWork 1" "D:\CLionProjectFolder\LabWork 1" "D:\CLionProjectFolder\LabWork 1\cmake-build-debug" "D:\CLionProjectFolder\LabWork 1\cmake-build-debug" "D:\CLionProjectFolder\LabWork 1\cmake-build-debug\CMakeFiles\LabWork_1.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/LabWork_1.dir/depend

