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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.22.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.22.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/coderepublic1/Downloads/Nairi/MainProject/myProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/coderepublic1/Downloads/Nairi/MainProject/myProject/build

# Include any dependencies generated for this target.
include Publisher/CMakeFiles/libP.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Publisher/CMakeFiles/libP.dir/compiler_depend.make

# Include the progress variables for this target.
include Publisher/CMakeFiles/libP.dir/progress.make

# Include the compile flags for this target's objects.
include Publisher/CMakeFiles/libP.dir/flags.make

Publisher/CMakeFiles/libP.dir/MyPublisher.cpp.o: Publisher/CMakeFiles/libP.dir/flags.make
Publisher/CMakeFiles/libP.dir/MyPublisher.cpp.o: ../Publisher/MyPublisher.cpp
Publisher/CMakeFiles/libP.dir/MyPublisher.cpp.o: Publisher/CMakeFiles/libP.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/coderepublic1/Downloads/Nairi/MainProject/myProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Publisher/CMakeFiles/libP.dir/MyPublisher.cpp.o"
	cd /Users/coderepublic1/Downloads/Nairi/MainProject/myProject/build/Publisher && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Publisher/CMakeFiles/libP.dir/MyPublisher.cpp.o -MF CMakeFiles/libP.dir/MyPublisher.cpp.o.d -o CMakeFiles/libP.dir/MyPublisher.cpp.o -c /Users/coderepublic1/Downloads/Nairi/MainProject/myProject/Publisher/MyPublisher.cpp

Publisher/CMakeFiles/libP.dir/MyPublisher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libP.dir/MyPublisher.cpp.i"
	cd /Users/coderepublic1/Downloads/Nairi/MainProject/myProject/build/Publisher && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/coderepublic1/Downloads/Nairi/MainProject/myProject/Publisher/MyPublisher.cpp > CMakeFiles/libP.dir/MyPublisher.cpp.i

Publisher/CMakeFiles/libP.dir/MyPublisher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libP.dir/MyPublisher.cpp.s"
	cd /Users/coderepublic1/Downloads/Nairi/MainProject/myProject/build/Publisher && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/coderepublic1/Downloads/Nairi/MainProject/myProject/Publisher/MyPublisher.cpp -o CMakeFiles/libP.dir/MyPublisher.cpp.s

# Object files for target libP
libP_OBJECTS = \
"CMakeFiles/libP.dir/MyPublisher.cpp.o"

# External object files for target libP
libP_EXTERNAL_OBJECTS =

Publisher/liblibP.dylib: Publisher/CMakeFiles/libP.dir/MyPublisher.cpp.o
Publisher/liblibP.dylib: Publisher/CMakeFiles/libP.dir/build.make
Publisher/liblibP.dylib: Publisher/CMakeFiles/libP.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/coderepublic1/Downloads/Nairi/MainProject/myProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library liblibP.dylib"
	cd /Users/coderepublic1/Downloads/Nairi/MainProject/myProject/build/Publisher && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libP.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Publisher/CMakeFiles/libP.dir/build: Publisher/liblibP.dylib
.PHONY : Publisher/CMakeFiles/libP.dir/build

Publisher/CMakeFiles/libP.dir/clean:
	cd /Users/coderepublic1/Downloads/Nairi/MainProject/myProject/build/Publisher && $(CMAKE_COMMAND) -P CMakeFiles/libP.dir/cmake_clean.cmake
.PHONY : Publisher/CMakeFiles/libP.dir/clean

Publisher/CMakeFiles/libP.dir/depend:
	cd /Users/coderepublic1/Downloads/Nairi/MainProject/myProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/coderepublic1/Downloads/Nairi/MainProject/myProject /Users/coderepublic1/Downloads/Nairi/MainProject/myProject/Publisher /Users/coderepublic1/Downloads/Nairi/MainProject/myProject/build /Users/coderepublic1/Downloads/Nairi/MainProject/myProject/build/Publisher /Users/coderepublic1/Downloads/Nairi/MainProject/myProject/build/Publisher/CMakeFiles/libP.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Publisher/CMakeFiles/libP.dir/depend

