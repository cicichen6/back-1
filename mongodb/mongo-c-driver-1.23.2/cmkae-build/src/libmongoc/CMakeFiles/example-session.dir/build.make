# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cici/mongo-c-driver-1.23.2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cici/mongo-c-driver-1.23.2/cmkae-build

# Include any dependencies generated for this target.
include src/libmongoc/CMakeFiles/example-session.dir/depend.make

# Include the progress variables for this target.
include src/libmongoc/CMakeFiles/example-session.dir/progress.make

# Include the compile flags for this target's objects.
include src/libmongoc/CMakeFiles/example-session.dir/flags.make

src/libmongoc/CMakeFiles/example-session.dir/examples/example-session.c.o: src/libmongoc/CMakeFiles/example-session.dir/flags.make
src/libmongoc/CMakeFiles/example-session.dir/examples/example-session.c.o: ../src/libmongoc/examples/example-session.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cici/mongo-c-driver-1.23.2/cmkae-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/libmongoc/CMakeFiles/example-session.dir/examples/example-session.c.o"
	cd /home/cici/mongo-c-driver-1.23.2/cmkae-build/src/libmongoc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/example-session.dir/examples/example-session.c.o   -c /home/cici/mongo-c-driver-1.23.2/src/libmongoc/examples/example-session.c

src/libmongoc/CMakeFiles/example-session.dir/examples/example-session.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/example-session.dir/examples/example-session.c.i"
	cd /home/cici/mongo-c-driver-1.23.2/cmkae-build/src/libmongoc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cici/mongo-c-driver-1.23.2/src/libmongoc/examples/example-session.c > CMakeFiles/example-session.dir/examples/example-session.c.i

src/libmongoc/CMakeFiles/example-session.dir/examples/example-session.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/example-session.dir/examples/example-session.c.s"
	cd /home/cici/mongo-c-driver-1.23.2/cmkae-build/src/libmongoc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cici/mongo-c-driver-1.23.2/src/libmongoc/examples/example-session.c -o CMakeFiles/example-session.dir/examples/example-session.c.s

# Object files for target example-session
example__session_OBJECTS = \
"CMakeFiles/example-session.dir/examples/example-session.c.o"

# External object files for target example-session
example__session_EXTERNAL_OBJECTS =

src/libmongoc/example-session: src/libmongoc/CMakeFiles/example-session.dir/examples/example-session.c.o
src/libmongoc/example-session: src/libmongoc/CMakeFiles/example-session.dir/build.make
src/libmongoc/example-session: src/libmongoc/libmongoc-1.0.so.0.0.0
src/libmongoc/example-session: /usr/lib/x86_64-linux-gnu/libsasl2.so
src/libmongoc/example-session: /usr/lib/x86_64-linux-gnu/libssl.so
src/libmongoc/example-session: /usr/lib/x86_64-linux-gnu/libcrypto.so
src/libmongoc/example-session: src/libbson/libbson-1.0.so.0.0.0
src/libmongoc/example-session: src/libmongoc/CMakeFiles/example-session.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cici/mongo-c-driver-1.23.2/cmkae-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable example-session"
	cd /home/cici/mongo-c-driver-1.23.2/cmkae-build/src/libmongoc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example-session.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/libmongoc/CMakeFiles/example-session.dir/build: src/libmongoc/example-session

.PHONY : src/libmongoc/CMakeFiles/example-session.dir/build

src/libmongoc/CMakeFiles/example-session.dir/clean:
	cd /home/cici/mongo-c-driver-1.23.2/cmkae-build/src/libmongoc && $(CMAKE_COMMAND) -P CMakeFiles/example-session.dir/cmake_clean.cmake
.PHONY : src/libmongoc/CMakeFiles/example-session.dir/clean

src/libmongoc/CMakeFiles/example-session.dir/depend:
	cd /home/cici/mongo-c-driver-1.23.2/cmkae-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cici/mongo-c-driver-1.23.2 /home/cici/mongo-c-driver-1.23.2/src/libmongoc /home/cici/mongo-c-driver-1.23.2/cmkae-build /home/cici/mongo-c-driver-1.23.2/cmkae-build/src/libmongoc /home/cici/mongo-c-driver-1.23.2/cmkae-build/src/libmongoc/CMakeFiles/example-session.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/libmongoc/CMakeFiles/example-session.dir/depend

