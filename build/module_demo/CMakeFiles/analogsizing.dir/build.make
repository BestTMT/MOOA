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
CMAKE_SOURCE_DIR = /home/asus/Desktop/cplusplushub/cmakeSizing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/asus/Desktop/cplusplushub/cmakeSizing/build

# Include any dependencies generated for this target.
include module_demo/CMakeFiles/analogsizing.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include module_demo/CMakeFiles/analogsizing.dir/compiler_depend.make

# Include the progress variables for this target.
include module_demo/CMakeFiles/analogsizing.dir/progress.make

# Include the compile flags for this target's objects.
include module_demo/CMakeFiles/analogsizing.dir/flags.make

module_demo/CMakeFiles/analogsizing.dir/main.cpp.o: module_demo/CMakeFiles/analogsizing.dir/flags.make
module_demo/CMakeFiles/analogsizing.dir/main.cpp.o: ../module_demo/main.cpp
module_demo/CMakeFiles/analogsizing.dir/main.cpp.o: module_demo/CMakeFiles/analogsizing.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/asus/Desktop/cplusplushub/cmakeSizing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object module_demo/CMakeFiles/analogsizing.dir/main.cpp.o"
	cd /home/asus/Desktop/cplusplushub/cmakeSizing/build/module_demo && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT module_demo/CMakeFiles/analogsizing.dir/main.cpp.o -MF CMakeFiles/analogsizing.dir/main.cpp.o.d -o CMakeFiles/analogsizing.dir/main.cpp.o -c /home/asus/Desktop/cplusplushub/cmakeSizing/module_demo/main.cpp

module_demo/CMakeFiles/analogsizing.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/analogsizing.dir/main.cpp.i"
	cd /home/asus/Desktop/cplusplushub/cmakeSizing/build/module_demo && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/asus/Desktop/cplusplushub/cmakeSizing/module_demo/main.cpp > CMakeFiles/analogsizing.dir/main.cpp.i

module_demo/CMakeFiles/analogsizing.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/analogsizing.dir/main.cpp.s"
	cd /home/asus/Desktop/cplusplushub/cmakeSizing/build/module_demo && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/asus/Desktop/cplusplushub/cmakeSizing/module_demo/main.cpp -o CMakeFiles/analogsizing.dir/main.cpp.s

# Object files for target analogsizing
analogsizing_OBJECTS = \
"CMakeFiles/analogsizing.dir/main.cpp.o"

# External object files for target analogsizing
analogsizing_EXTERNAL_OBJECTS =

bin/analogsizing: module_demo/CMakeFiles/analogsizing.dir/main.cpp.o
bin/analogsizing: module_demo/CMakeFiles/analogsizing.dir/build.make
bin/analogsizing: ../lib/libngspice.so
bin/analogsizing: module_nsga/libnsga_library.so
bin/analogsizing: simulator/libsimulator_library.so
bin/analogsizing: /home/asus/anaconda3/lib/libboost_date_time.so.1.73.0
bin/analogsizing: ../lib/libngspice.so
bin/analogsizing: module_demo/CMakeFiles/analogsizing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/asus/Desktop/cplusplushub/cmakeSizing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/analogsizing"
	cd /home/asus/Desktop/cplusplushub/cmakeSizing/build/module_demo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/analogsizing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
module_demo/CMakeFiles/analogsizing.dir/build: bin/analogsizing
.PHONY : module_demo/CMakeFiles/analogsizing.dir/build

module_demo/CMakeFiles/analogsizing.dir/clean:
	cd /home/asus/Desktop/cplusplushub/cmakeSizing/build/module_demo && $(CMAKE_COMMAND) -P CMakeFiles/analogsizing.dir/cmake_clean.cmake
.PHONY : module_demo/CMakeFiles/analogsizing.dir/clean

module_demo/CMakeFiles/analogsizing.dir/depend:
	cd /home/asus/Desktop/cplusplushub/cmakeSizing/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/asus/Desktop/cplusplushub/cmakeSizing /home/asus/Desktop/cplusplushub/cmakeSizing/module_demo /home/asus/Desktop/cplusplushub/cmakeSizing/build /home/asus/Desktop/cplusplushub/cmakeSizing/build/module_demo /home/asus/Desktop/cplusplushub/cmakeSizing/build/module_demo/CMakeFiles/analogsizing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : module_demo/CMakeFiles/analogsizing.dir/depend

