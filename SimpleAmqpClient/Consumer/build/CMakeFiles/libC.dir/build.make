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
CMAKE_SOURCE_DIR = /Users/coderepublic1/Downloads/Nairi/MainProject/myProject/Consumer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/coderepublic1/Downloads/Nairi/MainProject/myProject/Consumer/build

# Include any dependencies generated for this target.
include CMakeFiles/libC.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/libC.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/libC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libC.dir/flags.make

CMakeFiles/libC.dir/myConsumer.cpp.o: CMakeFiles/libC.dir/flags.make
CMakeFiles/libC.dir/myConsumer.cpp.o: ../myConsumer.cpp
CMakeFiles/libC.dir/myConsumer.cpp.o: CMakeFiles/libC.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/coderepublic1/Downloads/Nairi/MainProject/myProject/Consumer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/libC.dir/myConsumer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/libC.dir/myConsumer.cpp.o -MF CMakeFiles/libC.dir/myConsumer.cpp.o.d -o CMakeFiles/libC.dir/myConsumer.cpp.o -c /Users/coderepublic1/Downloads/Nairi/MainProject/myProject/Consumer/myConsumer.cpp

CMakeFiles/libC.dir/myConsumer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libC.dir/myConsumer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/coderepublic1/Downloads/Nairi/MainProject/myProject/Consumer/myConsumer.cpp > CMakeFiles/libC.dir/myConsumer.cpp.i

CMakeFiles/libC.dir/myConsumer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libC.dir/myConsumer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/coderepublic1/Downloads/Nairi/MainProject/myProject/Consumer/myConsumer.cpp -o CMakeFiles/libC.dir/myConsumer.cpp.s

# Object files for target libC
libC_OBJECTS = \
"CMakeFiles/libC.dir/myConsumer.cpp.o"

# External object files for target libC
libC_EXTERNAL_OBJECTS =

liblibC.a: CMakeFiles/libC.dir/myConsumer.cpp.o
liblibC.a: CMakeFiles/libC.dir/build.make
liblibC.a: CMakeFiles/libC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/coderepublic1/Downloads/Nairi/MainProject/myProject/Consumer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblibC.a"
	$(CMAKE_COMMAND) -P CMakeFiles/libC.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libC.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libC.dir/build: liblibC.a
.PHONY : CMakeFiles/libC.dir/build

CMakeFiles/libC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libC.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libC.dir/clean

CMakeFiles/libC.dir/depend:
	cd /Users/coderepublic1/Downloads/Nairi/MainProject/myProject/Consumer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/coderepublic1/Downloads/Nairi/MainProject/myProject/Consumer /Users/coderepublic1/Downloads/Nairi/MainProject/myProject/Consumer /Users/coderepublic1/Downloads/Nairi/MainProject/myProject/Consumer/build /Users/coderepublic1/Downloads/Nairi/MainProject/myProject/Consumer/build /Users/coderepublic1/Downloads/Nairi/MainProject/myProject/Consumer/build/CMakeFiles/libC.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libC.dir/depend

