# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\azubi\Documents\First Year\Semester 2\Software Engineering project\Focus\Focus"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\azubi\Documents\First Year\Semester 2\Software Engineering project\Focus\Focus\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Focus.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Focus.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Focus.dir/flags.make

CMakeFiles/Focus.dir/main.c.obj: CMakeFiles/Focus.dir/flags.make
CMakeFiles/Focus.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\azubi\Documents\First Year\Semester 2\Software Engineering project\Focus\Focus\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Focus.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Focus.dir\main.c.obj   -c "C:\Users\azubi\Documents\First Year\Semester 2\Software Engineering project\Focus\Focus\main.c"

CMakeFiles/Focus.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Focus.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\azubi\Documents\First Year\Semester 2\Software Engineering project\Focus\Focus\main.c" > CMakeFiles\Focus.dir\main.c.i

CMakeFiles/Focus.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Focus.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\azubi\Documents\First Year\Semester 2\Software Engineering project\Focus\Focus\main.c" -o CMakeFiles\Focus.dir\main.c.s

CMakeFiles/Focus.dir/input_output.c.obj: CMakeFiles/Focus.dir/flags.make
CMakeFiles/Focus.dir/input_output.c.obj: ../input_output.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\azubi\Documents\First Year\Semester 2\Software Engineering project\Focus\Focus\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Focus.dir/input_output.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Focus.dir\input_output.c.obj   -c "C:\Users\azubi\Documents\First Year\Semester 2\Software Engineering project\Focus\Focus\input_output.c"

CMakeFiles/Focus.dir/input_output.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Focus.dir/input_output.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\azubi\Documents\First Year\Semester 2\Software Engineering project\Focus\Focus\input_output.c" > CMakeFiles\Focus.dir\input_output.c.i

CMakeFiles/Focus.dir/input_output.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Focus.dir/input_output.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\azubi\Documents\First Year\Semester 2\Software Engineering project\Focus\Focus\input_output.c" -o CMakeFiles\Focus.dir\input_output.c.s

CMakeFiles/Focus.dir/game_init.c.obj: CMakeFiles/Focus.dir/flags.make
CMakeFiles/Focus.dir/game_init.c.obj: ../game_init.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\azubi\Documents\First Year\Semester 2\Software Engineering project\Focus\Focus\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Focus.dir/game_init.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Focus.dir\game_init.c.obj   -c "C:\Users\azubi\Documents\First Year\Semester 2\Software Engineering project\Focus\Focus\game_init.c"

CMakeFiles/Focus.dir/game_init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Focus.dir/game_init.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\azubi\Documents\First Year\Semester 2\Software Engineering project\Focus\Focus\game_init.c" > CMakeFiles\Focus.dir\game_init.c.i

CMakeFiles/Focus.dir/game_init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Focus.dir/game_init.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\azubi\Documents\First Year\Semester 2\Software Engineering project\Focus\Focus\game_init.c" -o CMakeFiles\Focus.dir\game_init.c.s

CMakeFiles/Focus.dir/PlayGame.c.obj: CMakeFiles/Focus.dir/flags.make
CMakeFiles/Focus.dir/PlayGame.c.obj: ../PlayGame.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\azubi\Documents\First Year\Semester 2\Software Engineering project\Focus\Focus\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Focus.dir/PlayGame.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Focus.dir\PlayGame.c.obj   -c "C:\Users\azubi\Documents\First Year\Semester 2\Software Engineering project\Focus\Focus\PlayGame.c"

CMakeFiles/Focus.dir/PlayGame.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Focus.dir/PlayGame.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\azubi\Documents\First Year\Semester 2\Software Engineering project\Focus\Focus\PlayGame.c" > CMakeFiles\Focus.dir\PlayGame.c.i

CMakeFiles/Focus.dir/PlayGame.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Focus.dir/PlayGame.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\azubi\Documents\First Year\Semester 2\Software Engineering project\Focus\Focus\PlayGame.c" -o CMakeFiles\Focus.dir\PlayGame.c.s

# Object files for target Focus
Focus_OBJECTS = \
"CMakeFiles/Focus.dir/main.c.obj" \
"CMakeFiles/Focus.dir/input_output.c.obj" \
"CMakeFiles/Focus.dir/game_init.c.obj" \
"CMakeFiles/Focus.dir/PlayGame.c.obj"

# External object files for target Focus
Focus_EXTERNAL_OBJECTS =

Focus.exe: CMakeFiles/Focus.dir/main.c.obj
Focus.exe: CMakeFiles/Focus.dir/input_output.c.obj
Focus.exe: CMakeFiles/Focus.dir/game_init.c.obj
Focus.exe: CMakeFiles/Focus.dir/PlayGame.c.obj
Focus.exe: CMakeFiles/Focus.dir/build.make
Focus.exe: CMakeFiles/Focus.dir/linklibs.rsp
Focus.exe: CMakeFiles/Focus.dir/objects1.rsp
Focus.exe: CMakeFiles/Focus.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\azubi\Documents\First Year\Semester 2\Software Engineering project\Focus\Focus\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable Focus.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Focus.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Focus.dir/build: Focus.exe

.PHONY : CMakeFiles/Focus.dir/build

CMakeFiles/Focus.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Focus.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Focus.dir/clean

CMakeFiles/Focus.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\azubi\Documents\First Year\Semester 2\Software Engineering project\Focus\Focus" "C:\Users\azubi\Documents\First Year\Semester 2\Software Engineering project\Focus\Focus" "C:\Users\azubi\Documents\First Year\Semester 2\Software Engineering project\Focus\Focus\cmake-build-debug" "C:\Users\azubi\Documents\First Year\Semester 2\Software Engineering project\Focus\Focus\cmake-build-debug" "C:\Users\azubi\Documents\First Year\Semester 2\Software Engineering project\Focus\Focus\cmake-build-debug\CMakeFiles\Focus.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Focus.dir/depend

