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
include src/libmongoc/CMakeFiles/mongoc-tail.dir/depend.make

# Include the progress variables for this target.
include src/libmongoc/CMakeFiles/mongoc-tail.dir/progress.make

# Include the compile flags for this target's objects.
include src/libmongoc/CMakeFiles/mongoc-tail.dir/flags.make

src/libmongoc/CMakeFiles/mongoc-tail.dir/examples/mongoc-tail.c.o: src/libmongoc/CMakeFiles/mongoc-tail.dir/flags.make
src/libmongoc/CMakeFiles/mongoc-tail.dir/examples/mongoc-tail.c.o: ../src/libmongoc/examples/mongoc-tail.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cici/mongo-c-driver-1.23.2/cmkae-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/libmongoc/CMakeFiles/mongoc-tail.dir/examples/mongoc-tail.c.o"
	cd /home/cici/mongo-c-driver-1.23.2/cmkae-build/src/libmongoc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mongoc-tail.dir/examples/mongoc-tail.c.o   -c /home/cici/mongo-c-driver-1.23.2/src/libmongoc/examples/mongoc-tail.c

src/libmongoc/CMakeFiles/mongoc-tail.dir/examples/mongoc-tail.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mongoc-tail.dir/examples/mongoc-tail.c.i"
	cd /home/cici/mongo-c-driver-1.23.2/cmkae-build/src/libmongoc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cici/mongo-c-driver-1.23.2/src/libmongoc/examples/mongoc-tail.c > CMakeFiles/mongoc-tail.dir/examples/mongoc-tail.c.i

src/libmongoc/CMakeFiles/mongoc-tail.dir/examples/mongoc-tail.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mongoc-tail.dir/examples/mongoc-tail.c.s"
	cd /home/cici/mongo-c-driver-1.23.2/cmkae-build/src/libmongoc && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cici/mongo-c-driver-1.23.2/src/libmongoc/examples/mongoc-tail.c -o CMakeFiles/mongoc-tail.dir/examples/mongoc-tail.c.s

# Object files for target mongoc-tail
mongoc__tail_OBJECTS = \
"CMakeFiles/mongoc-tail.dir/examples/mongoc-tail.c.o"

# External object files for target mongoc-tail
mongoc__tail_EXTERNAL_OBJECTS =

src/libmongoc/mongoc-tail: src/libmongoc/CMakeFiles/mongoc-tail.dir/examples/mongoc-tail.c.o
src/libmongoc/mongoc-tail: src/libmongoc/CMakeFiles/mongoc-tail.dir/build.make
src/libmongoc/mongoc-tail: src/libmongoc/libmongoc-1.0.so.0.0.0
src/libmongoc/mongoc-tail: /usr/lib/x86_64-linux-gnu/libsasl2.so
src/libmongoc/mongoc-tail: /usr/lib/x86_64-linux-gnu/libssl.so
src/libmongoc/mongoc-tail: /usr/lib/x86_64-linux-gnu/libcrypto.so
src/libmongoc/mongoc-tail: src/libbson/libbson-1.0.so.0.0.0
src/libmongoc/mongoc-tail: src/libmongoc/CMakeFiles/mongoc-tail.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cici/mongo-c-driver-1.23.2/cmkae-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable mongoc-tail"
	cd /home/cici/mongo-c-driver-1.23.2/cmkae-build/src/libmongoc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mongoc-tail.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/libmongoc/CMakeFiles/mongoc-tail.dir/build: src/libmongoc/mongoc-tail

.PHONY : src/libmongoc/CMakeFiles/mongoc-tail.dir/build

src/libmongoc/CMakeFiles/mongoc-tail.dir/clean:
	cd /home/cici/mongo-c-driver-1.23.2/cmkae-build/src/libmongoc && $(CMAKE_COMMAND) -P CMakeFiles/mongoc-tail.dir/cmake_clean.cmake
.PHONY : src/libmongoc/CMakeFiles/mongoc-tail.dir/clean

src/libmongoc/CMakeFiles/mongoc-tail.dir/depend:
	cd /home/cici/mongo-c-driver-1.23.2/cmkae-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cici/mongo-c-driver-1.23.2 /home/cici/mongo-c-driver-1.23.2/src/libmongoc /home/cici/mongo-c-driver-1.23.2/cmkae-build /home/cici/mongo-c-driver-1.23.2/cmkae-build/src/libmongoc /home/cici/mongo-c-driver-1.23.2/cmkae-build/src/libmongoc/CMakeFiles/mongoc-tail.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/libmongoc/CMakeFiles/mongoc-tail.dir/depend

