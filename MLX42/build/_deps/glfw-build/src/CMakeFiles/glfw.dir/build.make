# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/msavelie/Hive/FdF/MLX42

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/msavelie/Hive/FdF/MLX42/build

# Include any dependencies generated for this target.
include _deps/glfw-build/src/CMakeFiles/glfw.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include _deps/glfw-build/src/CMakeFiles/glfw.dir/compiler_depend.make

# Include the progress variables for this target.
include _deps/glfw-build/src/CMakeFiles/glfw.dir/progress.make

# Include the compile flags for this target's objects.
include _deps/glfw-build/src/CMakeFiles/glfw.dir/flags.make

_deps/glfw-build/src/CMakeFiles/glfw.dir/context.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/flags.make
_deps/glfw-build/src/CMakeFiles/glfw.dir/context.c.o: _deps/glfw-src/src/context.c
_deps/glfw-build/src/CMakeFiles/glfw.dir/context.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/msavelie/Hive/FdF/MLX42/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object _deps/glfw-build/src/CMakeFiles/glfw.dir/context.c.o"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wdeclaration-after-statement -MD -MT _deps/glfw-build/src/CMakeFiles/glfw.dir/context.c.o -MF CMakeFiles/glfw.dir/context.c.o.d -o CMakeFiles/glfw.dir/context.c.o -c /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/context.c

_deps/glfw-build/src/CMakeFiles/glfw.dir/context.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/context.c.i"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wdeclaration-after-statement -E /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/context.c > CMakeFiles/glfw.dir/context.c.i

_deps/glfw-build/src/CMakeFiles/glfw.dir/context.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/context.c.s"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wdeclaration-after-statement -S /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/context.c -o CMakeFiles/glfw.dir/context.c.s

_deps/glfw-build/src/CMakeFiles/glfw.dir/init.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/flags.make
_deps/glfw-build/src/CMakeFiles/glfw.dir/init.c.o: _deps/glfw-src/src/init.c
_deps/glfw-build/src/CMakeFiles/glfw.dir/init.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/msavelie/Hive/FdF/MLX42/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object _deps/glfw-build/src/CMakeFiles/glfw.dir/init.c.o"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wdeclaration-after-statement -MD -MT _deps/glfw-build/src/CMakeFiles/glfw.dir/init.c.o -MF CMakeFiles/glfw.dir/init.c.o.d -o CMakeFiles/glfw.dir/init.c.o -c /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/init.c

_deps/glfw-build/src/CMakeFiles/glfw.dir/init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/init.c.i"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wdeclaration-after-statement -E /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/init.c > CMakeFiles/glfw.dir/init.c.i

_deps/glfw-build/src/CMakeFiles/glfw.dir/init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/init.c.s"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wdeclaration-after-statement -S /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/init.c -o CMakeFiles/glfw.dir/init.c.s

_deps/glfw-build/src/CMakeFiles/glfw.dir/input.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/flags.make
_deps/glfw-build/src/CMakeFiles/glfw.dir/input.c.o: _deps/glfw-src/src/input.c
_deps/glfw-build/src/CMakeFiles/glfw.dir/input.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/msavelie/Hive/FdF/MLX42/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object _deps/glfw-build/src/CMakeFiles/glfw.dir/input.c.o"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wdeclaration-after-statement -MD -MT _deps/glfw-build/src/CMakeFiles/glfw.dir/input.c.o -MF CMakeFiles/glfw.dir/input.c.o.d -o CMakeFiles/glfw.dir/input.c.o -c /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/input.c

_deps/glfw-build/src/CMakeFiles/glfw.dir/input.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/input.c.i"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wdeclaration-after-statement -E /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/input.c > CMakeFiles/glfw.dir/input.c.i

_deps/glfw-build/src/CMakeFiles/glfw.dir/input.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/input.c.s"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wdeclaration-after-statement -S /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/input.c -o CMakeFiles/glfw.dir/input.c.s

_deps/glfw-build/src/CMakeFiles/glfw.dir/monitor.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/flags.make
_deps/glfw-build/src/CMakeFiles/glfw.dir/monitor.c.o: _deps/glfw-src/src/monitor.c
_deps/glfw-build/src/CMakeFiles/glfw.dir/monitor.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/msavelie/Hive/FdF/MLX42/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object _deps/glfw-build/src/CMakeFiles/glfw.dir/monitor.c.o"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wdeclaration-after-statement -MD -MT _deps/glfw-build/src/CMakeFiles/glfw.dir/monitor.c.o -MF CMakeFiles/glfw.dir/monitor.c.o.d -o CMakeFiles/glfw.dir/monitor.c.o -c /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/monitor.c

_deps/glfw-build/src/CMakeFiles/glfw.dir/monitor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/monitor.c.i"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wdeclaration-after-statement -E /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/monitor.c > CMakeFiles/glfw.dir/monitor.c.i

_deps/glfw-build/src/CMakeFiles/glfw.dir/monitor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/monitor.c.s"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wdeclaration-after-statement -S /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/monitor.c -o CMakeFiles/glfw.dir/monitor.c.s

_deps/glfw-build/src/CMakeFiles/glfw.dir/vulkan.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/flags.make
_deps/glfw-build/src/CMakeFiles/glfw.dir/vulkan.c.o: _deps/glfw-src/src/vulkan.c
_deps/glfw-build/src/CMakeFiles/glfw.dir/vulkan.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/msavelie/Hive/FdF/MLX42/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object _deps/glfw-build/src/CMakeFiles/glfw.dir/vulkan.c.o"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wdeclaration-after-statement -MD -MT _deps/glfw-build/src/CMakeFiles/glfw.dir/vulkan.c.o -MF CMakeFiles/glfw.dir/vulkan.c.o.d -o CMakeFiles/glfw.dir/vulkan.c.o -c /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/vulkan.c

_deps/glfw-build/src/CMakeFiles/glfw.dir/vulkan.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/vulkan.c.i"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wdeclaration-after-statement -E /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/vulkan.c > CMakeFiles/glfw.dir/vulkan.c.i

_deps/glfw-build/src/CMakeFiles/glfw.dir/vulkan.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/vulkan.c.s"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wdeclaration-after-statement -S /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/vulkan.c -o CMakeFiles/glfw.dir/vulkan.c.s

_deps/glfw-build/src/CMakeFiles/glfw.dir/window.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/flags.make
_deps/glfw-build/src/CMakeFiles/glfw.dir/window.c.o: _deps/glfw-src/src/window.c
_deps/glfw-build/src/CMakeFiles/glfw.dir/window.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/msavelie/Hive/FdF/MLX42/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object _deps/glfw-build/src/CMakeFiles/glfw.dir/window.c.o"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wdeclaration-after-statement -MD -MT _deps/glfw-build/src/CMakeFiles/glfw.dir/window.c.o -MF CMakeFiles/glfw.dir/window.c.o.d -o CMakeFiles/glfw.dir/window.c.o -c /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/window.c

_deps/glfw-build/src/CMakeFiles/glfw.dir/window.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/window.c.i"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wdeclaration-after-statement -E /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/window.c > CMakeFiles/glfw.dir/window.c.i

_deps/glfw-build/src/CMakeFiles/glfw.dir/window.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/window.c.s"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wdeclaration-after-statement -S /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/window.c -o CMakeFiles/glfw.dir/window.c.s

_deps/glfw-build/src/CMakeFiles/glfw.dir/x11_init.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/flags.make
_deps/glfw-build/src/CMakeFiles/glfw.dir/x11_init.c.o: _deps/glfw-src/src/x11_init.c
_deps/glfw-build/src/CMakeFiles/glfw.dir/x11_init.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/msavelie/Hive/FdF/MLX42/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object _deps/glfw-build/src/CMakeFiles/glfw.dir/x11_init.c.o"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/glfw-build/src/CMakeFiles/glfw.dir/x11_init.c.o -MF CMakeFiles/glfw.dir/x11_init.c.o.d -o CMakeFiles/glfw.dir/x11_init.c.o -c /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/x11_init.c

_deps/glfw-build/src/CMakeFiles/glfw.dir/x11_init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/x11_init.c.i"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/x11_init.c > CMakeFiles/glfw.dir/x11_init.c.i

_deps/glfw-build/src/CMakeFiles/glfw.dir/x11_init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/x11_init.c.s"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/x11_init.c -o CMakeFiles/glfw.dir/x11_init.c.s

_deps/glfw-build/src/CMakeFiles/glfw.dir/x11_monitor.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/flags.make
_deps/glfw-build/src/CMakeFiles/glfw.dir/x11_monitor.c.o: _deps/glfw-src/src/x11_monitor.c
_deps/glfw-build/src/CMakeFiles/glfw.dir/x11_monitor.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/msavelie/Hive/FdF/MLX42/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object _deps/glfw-build/src/CMakeFiles/glfw.dir/x11_monitor.c.o"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/glfw-build/src/CMakeFiles/glfw.dir/x11_monitor.c.o -MF CMakeFiles/glfw.dir/x11_monitor.c.o.d -o CMakeFiles/glfw.dir/x11_monitor.c.o -c /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/x11_monitor.c

_deps/glfw-build/src/CMakeFiles/glfw.dir/x11_monitor.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/x11_monitor.c.i"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/x11_monitor.c > CMakeFiles/glfw.dir/x11_monitor.c.i

_deps/glfw-build/src/CMakeFiles/glfw.dir/x11_monitor.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/x11_monitor.c.s"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/x11_monitor.c -o CMakeFiles/glfw.dir/x11_monitor.c.s

_deps/glfw-build/src/CMakeFiles/glfw.dir/x11_window.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/flags.make
_deps/glfw-build/src/CMakeFiles/glfw.dir/x11_window.c.o: _deps/glfw-src/src/x11_window.c
_deps/glfw-build/src/CMakeFiles/glfw.dir/x11_window.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/msavelie/Hive/FdF/MLX42/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object _deps/glfw-build/src/CMakeFiles/glfw.dir/x11_window.c.o"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/glfw-build/src/CMakeFiles/glfw.dir/x11_window.c.o -MF CMakeFiles/glfw.dir/x11_window.c.o.d -o CMakeFiles/glfw.dir/x11_window.c.o -c /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/x11_window.c

_deps/glfw-build/src/CMakeFiles/glfw.dir/x11_window.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/x11_window.c.i"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/x11_window.c > CMakeFiles/glfw.dir/x11_window.c.i

_deps/glfw-build/src/CMakeFiles/glfw.dir/x11_window.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/x11_window.c.s"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/x11_window.c -o CMakeFiles/glfw.dir/x11_window.c.s

_deps/glfw-build/src/CMakeFiles/glfw.dir/xkb_unicode.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/flags.make
_deps/glfw-build/src/CMakeFiles/glfw.dir/xkb_unicode.c.o: _deps/glfw-src/src/xkb_unicode.c
_deps/glfw-build/src/CMakeFiles/glfw.dir/xkb_unicode.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/msavelie/Hive/FdF/MLX42/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object _deps/glfw-build/src/CMakeFiles/glfw.dir/xkb_unicode.c.o"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/glfw-build/src/CMakeFiles/glfw.dir/xkb_unicode.c.o -MF CMakeFiles/glfw.dir/xkb_unicode.c.o.d -o CMakeFiles/glfw.dir/xkb_unicode.c.o -c /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/xkb_unicode.c

_deps/glfw-build/src/CMakeFiles/glfw.dir/xkb_unicode.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/xkb_unicode.c.i"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/xkb_unicode.c > CMakeFiles/glfw.dir/xkb_unicode.c.i

_deps/glfw-build/src/CMakeFiles/glfw.dir/xkb_unicode.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/xkb_unicode.c.s"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/xkb_unicode.c -o CMakeFiles/glfw.dir/xkb_unicode.c.s

_deps/glfw-build/src/CMakeFiles/glfw.dir/posix_time.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/flags.make
_deps/glfw-build/src/CMakeFiles/glfw.dir/posix_time.c.o: _deps/glfw-src/src/posix_time.c
_deps/glfw-build/src/CMakeFiles/glfw.dir/posix_time.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/msavelie/Hive/FdF/MLX42/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object _deps/glfw-build/src/CMakeFiles/glfw.dir/posix_time.c.o"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/glfw-build/src/CMakeFiles/glfw.dir/posix_time.c.o -MF CMakeFiles/glfw.dir/posix_time.c.o.d -o CMakeFiles/glfw.dir/posix_time.c.o -c /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/posix_time.c

_deps/glfw-build/src/CMakeFiles/glfw.dir/posix_time.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/posix_time.c.i"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/posix_time.c > CMakeFiles/glfw.dir/posix_time.c.i

_deps/glfw-build/src/CMakeFiles/glfw.dir/posix_time.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/posix_time.c.s"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/posix_time.c -o CMakeFiles/glfw.dir/posix_time.c.s

_deps/glfw-build/src/CMakeFiles/glfw.dir/posix_thread.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/flags.make
_deps/glfw-build/src/CMakeFiles/glfw.dir/posix_thread.c.o: _deps/glfw-src/src/posix_thread.c
_deps/glfw-build/src/CMakeFiles/glfw.dir/posix_thread.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/msavelie/Hive/FdF/MLX42/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object _deps/glfw-build/src/CMakeFiles/glfw.dir/posix_thread.c.o"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/glfw-build/src/CMakeFiles/glfw.dir/posix_thread.c.o -MF CMakeFiles/glfw.dir/posix_thread.c.o.d -o CMakeFiles/glfw.dir/posix_thread.c.o -c /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/posix_thread.c

_deps/glfw-build/src/CMakeFiles/glfw.dir/posix_thread.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/posix_thread.c.i"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/posix_thread.c > CMakeFiles/glfw.dir/posix_thread.c.i

_deps/glfw-build/src/CMakeFiles/glfw.dir/posix_thread.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/posix_thread.c.s"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/posix_thread.c -o CMakeFiles/glfw.dir/posix_thread.c.s

_deps/glfw-build/src/CMakeFiles/glfw.dir/glx_context.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/flags.make
_deps/glfw-build/src/CMakeFiles/glfw.dir/glx_context.c.o: _deps/glfw-src/src/glx_context.c
_deps/glfw-build/src/CMakeFiles/glfw.dir/glx_context.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/msavelie/Hive/FdF/MLX42/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object _deps/glfw-build/src/CMakeFiles/glfw.dir/glx_context.c.o"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/glfw-build/src/CMakeFiles/glfw.dir/glx_context.c.o -MF CMakeFiles/glfw.dir/glx_context.c.o.d -o CMakeFiles/glfw.dir/glx_context.c.o -c /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/glx_context.c

_deps/glfw-build/src/CMakeFiles/glfw.dir/glx_context.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/glx_context.c.i"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/glx_context.c > CMakeFiles/glfw.dir/glx_context.c.i

_deps/glfw-build/src/CMakeFiles/glfw.dir/glx_context.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/glx_context.c.s"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/glx_context.c -o CMakeFiles/glfw.dir/glx_context.c.s

_deps/glfw-build/src/CMakeFiles/glfw.dir/egl_context.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/flags.make
_deps/glfw-build/src/CMakeFiles/glfw.dir/egl_context.c.o: _deps/glfw-src/src/egl_context.c
_deps/glfw-build/src/CMakeFiles/glfw.dir/egl_context.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/msavelie/Hive/FdF/MLX42/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object _deps/glfw-build/src/CMakeFiles/glfw.dir/egl_context.c.o"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wdeclaration-after-statement -MD -MT _deps/glfw-build/src/CMakeFiles/glfw.dir/egl_context.c.o -MF CMakeFiles/glfw.dir/egl_context.c.o.d -o CMakeFiles/glfw.dir/egl_context.c.o -c /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/egl_context.c

_deps/glfw-build/src/CMakeFiles/glfw.dir/egl_context.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/egl_context.c.i"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wdeclaration-after-statement -E /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/egl_context.c > CMakeFiles/glfw.dir/egl_context.c.i

_deps/glfw-build/src/CMakeFiles/glfw.dir/egl_context.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/egl_context.c.s"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wdeclaration-after-statement -S /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/egl_context.c -o CMakeFiles/glfw.dir/egl_context.c.s

_deps/glfw-build/src/CMakeFiles/glfw.dir/osmesa_context.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/flags.make
_deps/glfw-build/src/CMakeFiles/glfw.dir/osmesa_context.c.o: _deps/glfw-src/src/osmesa_context.c
_deps/glfw-build/src/CMakeFiles/glfw.dir/osmesa_context.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/msavelie/Hive/FdF/MLX42/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object _deps/glfw-build/src/CMakeFiles/glfw.dir/osmesa_context.c.o"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wdeclaration-after-statement -MD -MT _deps/glfw-build/src/CMakeFiles/glfw.dir/osmesa_context.c.o -MF CMakeFiles/glfw.dir/osmesa_context.c.o.d -o CMakeFiles/glfw.dir/osmesa_context.c.o -c /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/osmesa_context.c

_deps/glfw-build/src/CMakeFiles/glfw.dir/osmesa_context.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/osmesa_context.c.i"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wdeclaration-after-statement -E /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/osmesa_context.c > CMakeFiles/glfw.dir/osmesa_context.c.i

_deps/glfw-build/src/CMakeFiles/glfw.dir/osmesa_context.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/osmesa_context.c.s"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -Wdeclaration-after-statement -S /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/osmesa_context.c -o CMakeFiles/glfw.dir/osmesa_context.c.s

_deps/glfw-build/src/CMakeFiles/glfw.dir/linux_joystick.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/flags.make
_deps/glfw-build/src/CMakeFiles/glfw.dir/linux_joystick.c.o: _deps/glfw-src/src/linux_joystick.c
_deps/glfw-build/src/CMakeFiles/glfw.dir/linux_joystick.c.o: _deps/glfw-build/src/CMakeFiles/glfw.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/msavelie/Hive/FdF/MLX42/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object _deps/glfw-build/src/CMakeFiles/glfw.dir/linux_joystick.c.o"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT _deps/glfw-build/src/CMakeFiles/glfw.dir/linux_joystick.c.o -MF CMakeFiles/glfw.dir/linux_joystick.c.o.d -o CMakeFiles/glfw.dir/linux_joystick.c.o -c /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/linux_joystick.c

_deps/glfw-build/src/CMakeFiles/glfw.dir/linux_joystick.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfw.dir/linux_joystick.c.i"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/linux_joystick.c > CMakeFiles/glfw.dir/linux_joystick.c.i

_deps/glfw-build/src/CMakeFiles/glfw.dir/linux_joystick.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfw.dir/linux_joystick.c.s"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src/linux_joystick.c -o CMakeFiles/glfw.dir/linux_joystick.c.s

# Object files for target glfw
glfw_OBJECTS = \
"CMakeFiles/glfw.dir/context.c.o" \
"CMakeFiles/glfw.dir/init.c.o" \
"CMakeFiles/glfw.dir/input.c.o" \
"CMakeFiles/glfw.dir/monitor.c.o" \
"CMakeFiles/glfw.dir/vulkan.c.o" \
"CMakeFiles/glfw.dir/window.c.o" \
"CMakeFiles/glfw.dir/x11_init.c.o" \
"CMakeFiles/glfw.dir/x11_monitor.c.o" \
"CMakeFiles/glfw.dir/x11_window.c.o" \
"CMakeFiles/glfw.dir/xkb_unicode.c.o" \
"CMakeFiles/glfw.dir/posix_time.c.o" \
"CMakeFiles/glfw.dir/posix_thread.c.o" \
"CMakeFiles/glfw.dir/glx_context.c.o" \
"CMakeFiles/glfw.dir/egl_context.c.o" \
"CMakeFiles/glfw.dir/osmesa_context.c.o" \
"CMakeFiles/glfw.dir/linux_joystick.c.o"

# External object files for target glfw
glfw_EXTERNAL_OBJECTS =

_deps/glfw-build/src/libglfw3.a: _deps/glfw-build/src/CMakeFiles/glfw.dir/context.c.o
_deps/glfw-build/src/libglfw3.a: _deps/glfw-build/src/CMakeFiles/glfw.dir/init.c.o
_deps/glfw-build/src/libglfw3.a: _deps/glfw-build/src/CMakeFiles/glfw.dir/input.c.o
_deps/glfw-build/src/libglfw3.a: _deps/glfw-build/src/CMakeFiles/glfw.dir/monitor.c.o
_deps/glfw-build/src/libglfw3.a: _deps/glfw-build/src/CMakeFiles/glfw.dir/vulkan.c.o
_deps/glfw-build/src/libglfw3.a: _deps/glfw-build/src/CMakeFiles/glfw.dir/window.c.o
_deps/glfw-build/src/libglfw3.a: _deps/glfw-build/src/CMakeFiles/glfw.dir/x11_init.c.o
_deps/glfw-build/src/libglfw3.a: _deps/glfw-build/src/CMakeFiles/glfw.dir/x11_monitor.c.o
_deps/glfw-build/src/libglfw3.a: _deps/glfw-build/src/CMakeFiles/glfw.dir/x11_window.c.o
_deps/glfw-build/src/libglfw3.a: _deps/glfw-build/src/CMakeFiles/glfw.dir/xkb_unicode.c.o
_deps/glfw-build/src/libglfw3.a: _deps/glfw-build/src/CMakeFiles/glfw.dir/posix_time.c.o
_deps/glfw-build/src/libglfw3.a: _deps/glfw-build/src/CMakeFiles/glfw.dir/posix_thread.c.o
_deps/glfw-build/src/libglfw3.a: _deps/glfw-build/src/CMakeFiles/glfw.dir/glx_context.c.o
_deps/glfw-build/src/libglfw3.a: _deps/glfw-build/src/CMakeFiles/glfw.dir/egl_context.c.o
_deps/glfw-build/src/libglfw3.a: _deps/glfw-build/src/CMakeFiles/glfw.dir/osmesa_context.c.o
_deps/glfw-build/src/libglfw3.a: _deps/glfw-build/src/CMakeFiles/glfw.dir/linux_joystick.c.o
_deps/glfw-build/src/libglfw3.a: _deps/glfw-build/src/CMakeFiles/glfw.dir/build.make
_deps/glfw-build/src/libglfw3.a: _deps/glfw-build/src/CMakeFiles/glfw.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/msavelie/Hive/FdF/MLX42/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking C static library libglfw3.a"
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && $(CMAKE_COMMAND) -P CMakeFiles/glfw.dir/cmake_clean_target.cmake
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glfw.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
_deps/glfw-build/src/CMakeFiles/glfw.dir/build: _deps/glfw-build/src/libglfw3.a
.PHONY : _deps/glfw-build/src/CMakeFiles/glfw.dir/build

_deps/glfw-build/src/CMakeFiles/glfw.dir/clean:
	cd /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src && $(CMAKE_COMMAND) -P CMakeFiles/glfw.dir/cmake_clean.cmake
.PHONY : _deps/glfw-build/src/CMakeFiles/glfw.dir/clean

_deps/glfw-build/src/CMakeFiles/glfw.dir/depend:
	cd /home/msavelie/Hive/FdF/MLX42/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/msavelie/Hive/FdF/MLX42 /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-src/src /home/msavelie/Hive/FdF/MLX42/build /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src /home/msavelie/Hive/FdF/MLX42/build/_deps/glfw-build/src/CMakeFiles/glfw.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : _deps/glfw-build/src/CMakeFiles/glfw.dir/depend

