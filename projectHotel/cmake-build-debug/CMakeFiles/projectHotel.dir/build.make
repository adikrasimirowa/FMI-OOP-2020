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
CMAKE_COMMAND = /home/adi/Documents/clion-2020.1.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/adi/Documents/clion-2020.1.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/adi/Documents/c++/oop/FOR GIT/projectHotel"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/adi/Documents/c++/oop/FOR GIT/projectHotel/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/projectHotel.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/projectHotel.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/projectHotel.dir/flags.make

CMakeFiles/projectHotel.dir/main.cpp.o: CMakeFiles/projectHotel.dir/flags.make
CMakeFiles/projectHotel.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/adi/Documents/c++/oop/FOR GIT/projectHotel/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/projectHotel.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/projectHotel.dir/main.cpp.o -c "/home/adi/Documents/c++/oop/FOR GIT/projectHotel/main.cpp"

CMakeFiles/projectHotel.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/projectHotel.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/adi/Documents/c++/oop/FOR GIT/projectHotel/main.cpp" > CMakeFiles/projectHotel.dir/main.cpp.i

CMakeFiles/projectHotel.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/projectHotel.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/adi/Documents/c++/oop/FOR GIT/projectHotel/main.cpp" -o CMakeFiles/projectHotel.dir/main.cpp.s

# Object files for target projectHotel
projectHotel_OBJECTS = \
"CMakeFiles/projectHotel.dir/main.cpp.o"

# External object files for target projectHotel
projectHotel_EXTERNAL_OBJECTS =

projectHotel: CMakeFiles/projectHotel.dir/main.cpp.o
projectHotel: CMakeFiles/projectHotel.dir/build.make
projectHotel: CMakeFiles/projectHotel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/adi/Documents/c++/oop/FOR GIT/projectHotel/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable projectHotel"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/projectHotel.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/projectHotel.dir/build: projectHotel

.PHONY : CMakeFiles/projectHotel.dir/build

CMakeFiles/projectHotel.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/projectHotel.dir/cmake_clean.cmake
.PHONY : CMakeFiles/projectHotel.dir/clean

CMakeFiles/projectHotel.dir/depend:
	cd "/home/adi/Documents/c++/oop/FOR GIT/projectHotel/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/adi/Documents/c++/oop/FOR GIT/projectHotel" "/home/adi/Documents/c++/oop/FOR GIT/projectHotel" "/home/adi/Documents/c++/oop/FOR GIT/projectHotel/cmake-build-debug" "/home/adi/Documents/c++/oop/FOR GIT/projectHotel/cmake-build-debug" "/home/adi/Documents/c++/oop/FOR GIT/projectHotel/cmake-build-debug/CMakeFiles/projectHotel.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/projectHotel.dir/depend
