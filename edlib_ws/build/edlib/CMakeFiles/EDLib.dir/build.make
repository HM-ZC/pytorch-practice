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
CMAKE_SOURCE_DIR = /root/edlib_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/edlib_ws/build

# Include any dependencies generated for this target.
include edlib/CMakeFiles/EDLib.dir/depend.make

# Include the progress variables for this target.
include edlib/CMakeFiles/EDLib.dir/progress.make

# Include the compile flags for this target's objects.
include edlib/CMakeFiles/EDLib.dir/flags.make

edlib/CMakeFiles/EDLib.dir/src/ED.cpp.o: edlib/CMakeFiles/EDLib.dir/flags.make
edlib/CMakeFiles/EDLib.dir/src/ED.cpp.o: /root/edlib_ws/src/edlib/src/ED.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/edlib_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object edlib/CMakeFiles/EDLib.dir/src/ED.cpp.o"
	cd /root/edlib_ws/build/edlib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EDLib.dir/src/ED.cpp.o -c /root/edlib_ws/src/edlib/src/ED.cpp

edlib/CMakeFiles/EDLib.dir/src/ED.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EDLib.dir/src/ED.cpp.i"
	cd /root/edlib_ws/build/edlib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/edlib_ws/src/edlib/src/ED.cpp > CMakeFiles/EDLib.dir/src/ED.cpp.i

edlib/CMakeFiles/EDLib.dir/src/ED.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EDLib.dir/src/ED.cpp.s"
	cd /root/edlib_ws/build/edlib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/edlib_ws/src/edlib/src/ED.cpp -o CMakeFiles/EDLib.dir/src/ED.cpp.s

edlib/CMakeFiles/EDLib.dir/src/EDCircles.cpp.o: edlib/CMakeFiles/EDLib.dir/flags.make
edlib/CMakeFiles/EDLib.dir/src/EDCircles.cpp.o: /root/edlib_ws/src/edlib/src/EDCircles.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/edlib_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object edlib/CMakeFiles/EDLib.dir/src/EDCircles.cpp.o"
	cd /root/edlib_ws/build/edlib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EDLib.dir/src/EDCircles.cpp.o -c /root/edlib_ws/src/edlib/src/EDCircles.cpp

edlib/CMakeFiles/EDLib.dir/src/EDCircles.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EDLib.dir/src/EDCircles.cpp.i"
	cd /root/edlib_ws/build/edlib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/edlib_ws/src/edlib/src/EDCircles.cpp > CMakeFiles/EDLib.dir/src/EDCircles.cpp.i

edlib/CMakeFiles/EDLib.dir/src/EDCircles.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EDLib.dir/src/EDCircles.cpp.s"
	cd /root/edlib_ws/build/edlib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/edlib_ws/src/edlib/src/EDCircles.cpp -o CMakeFiles/EDLib.dir/src/EDCircles.cpp.s

edlib/CMakeFiles/EDLib.dir/src/EDColor.cpp.o: edlib/CMakeFiles/EDLib.dir/flags.make
edlib/CMakeFiles/EDLib.dir/src/EDColor.cpp.o: /root/edlib_ws/src/edlib/src/EDColor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/edlib_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object edlib/CMakeFiles/EDLib.dir/src/EDColor.cpp.o"
	cd /root/edlib_ws/build/edlib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EDLib.dir/src/EDColor.cpp.o -c /root/edlib_ws/src/edlib/src/EDColor.cpp

edlib/CMakeFiles/EDLib.dir/src/EDColor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EDLib.dir/src/EDColor.cpp.i"
	cd /root/edlib_ws/build/edlib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/edlib_ws/src/edlib/src/EDColor.cpp > CMakeFiles/EDLib.dir/src/EDColor.cpp.i

edlib/CMakeFiles/EDLib.dir/src/EDColor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EDLib.dir/src/EDColor.cpp.s"
	cd /root/edlib_ws/build/edlib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/edlib_ws/src/edlib/src/EDColor.cpp -o CMakeFiles/EDLib.dir/src/EDColor.cpp.s

edlib/CMakeFiles/EDLib.dir/src/EDLines.cpp.o: edlib/CMakeFiles/EDLib.dir/flags.make
edlib/CMakeFiles/EDLib.dir/src/EDLines.cpp.o: /root/edlib_ws/src/edlib/src/EDLines.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/edlib_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object edlib/CMakeFiles/EDLib.dir/src/EDLines.cpp.o"
	cd /root/edlib_ws/build/edlib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EDLib.dir/src/EDLines.cpp.o -c /root/edlib_ws/src/edlib/src/EDLines.cpp

edlib/CMakeFiles/EDLib.dir/src/EDLines.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EDLib.dir/src/EDLines.cpp.i"
	cd /root/edlib_ws/build/edlib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/edlib_ws/src/edlib/src/EDLines.cpp > CMakeFiles/EDLib.dir/src/EDLines.cpp.i

edlib/CMakeFiles/EDLib.dir/src/EDLines.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EDLib.dir/src/EDLines.cpp.s"
	cd /root/edlib_ws/build/edlib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/edlib_ws/src/edlib/src/EDLines.cpp -o CMakeFiles/EDLib.dir/src/EDLines.cpp.s

edlib/CMakeFiles/EDLib.dir/src/EDPF.cpp.o: edlib/CMakeFiles/EDLib.dir/flags.make
edlib/CMakeFiles/EDLib.dir/src/EDPF.cpp.o: /root/edlib_ws/src/edlib/src/EDPF.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/edlib_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object edlib/CMakeFiles/EDLib.dir/src/EDPF.cpp.o"
	cd /root/edlib_ws/build/edlib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EDLib.dir/src/EDPF.cpp.o -c /root/edlib_ws/src/edlib/src/EDPF.cpp

edlib/CMakeFiles/EDLib.dir/src/EDPF.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EDLib.dir/src/EDPF.cpp.i"
	cd /root/edlib_ws/build/edlib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/edlib_ws/src/edlib/src/EDPF.cpp > CMakeFiles/EDLib.dir/src/EDPF.cpp.i

edlib/CMakeFiles/EDLib.dir/src/EDPF.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EDLib.dir/src/EDPF.cpp.s"
	cd /root/edlib_ws/build/edlib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/edlib_ws/src/edlib/src/EDPF.cpp -o CMakeFiles/EDLib.dir/src/EDPF.cpp.s

edlib/CMakeFiles/EDLib.dir/src/NFA.cpp.o: edlib/CMakeFiles/EDLib.dir/flags.make
edlib/CMakeFiles/EDLib.dir/src/NFA.cpp.o: /root/edlib_ws/src/edlib/src/NFA.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/edlib_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object edlib/CMakeFiles/EDLib.dir/src/NFA.cpp.o"
	cd /root/edlib_ws/build/edlib && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EDLib.dir/src/NFA.cpp.o -c /root/edlib_ws/src/edlib/src/NFA.cpp

edlib/CMakeFiles/EDLib.dir/src/NFA.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EDLib.dir/src/NFA.cpp.i"
	cd /root/edlib_ws/build/edlib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/edlib_ws/src/edlib/src/NFA.cpp > CMakeFiles/EDLib.dir/src/NFA.cpp.i

edlib/CMakeFiles/EDLib.dir/src/NFA.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EDLib.dir/src/NFA.cpp.s"
	cd /root/edlib_ws/build/edlib && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/edlib_ws/src/edlib/src/NFA.cpp -o CMakeFiles/EDLib.dir/src/NFA.cpp.s

# Object files for target EDLib
EDLib_OBJECTS = \
"CMakeFiles/EDLib.dir/src/ED.cpp.o" \
"CMakeFiles/EDLib.dir/src/EDCircles.cpp.o" \
"CMakeFiles/EDLib.dir/src/EDColor.cpp.o" \
"CMakeFiles/EDLib.dir/src/EDLines.cpp.o" \
"CMakeFiles/EDLib.dir/src/EDPF.cpp.o" \
"CMakeFiles/EDLib.dir/src/NFA.cpp.o"

# External object files for target EDLib
EDLib_EXTERNAL_OBJECTS =

/root/edlib_ws/devel/lib/libEDLib.a: edlib/CMakeFiles/EDLib.dir/src/ED.cpp.o
/root/edlib_ws/devel/lib/libEDLib.a: edlib/CMakeFiles/EDLib.dir/src/EDCircles.cpp.o
/root/edlib_ws/devel/lib/libEDLib.a: edlib/CMakeFiles/EDLib.dir/src/EDColor.cpp.o
/root/edlib_ws/devel/lib/libEDLib.a: edlib/CMakeFiles/EDLib.dir/src/EDLines.cpp.o
/root/edlib_ws/devel/lib/libEDLib.a: edlib/CMakeFiles/EDLib.dir/src/EDPF.cpp.o
/root/edlib_ws/devel/lib/libEDLib.a: edlib/CMakeFiles/EDLib.dir/src/NFA.cpp.o
/root/edlib_ws/devel/lib/libEDLib.a: edlib/CMakeFiles/EDLib.dir/build.make
/root/edlib_ws/devel/lib/libEDLib.a: edlib/CMakeFiles/EDLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/edlib_ws/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library /root/edlib_ws/devel/lib/libEDLib.a"
	cd /root/edlib_ws/build/edlib && $(CMAKE_COMMAND) -P CMakeFiles/EDLib.dir/cmake_clean_target.cmake
	cd /root/edlib_ws/build/edlib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/EDLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
edlib/CMakeFiles/EDLib.dir/build: /root/edlib_ws/devel/lib/libEDLib.a

.PHONY : edlib/CMakeFiles/EDLib.dir/build

edlib/CMakeFiles/EDLib.dir/clean:
	cd /root/edlib_ws/build/edlib && $(CMAKE_COMMAND) -P CMakeFiles/EDLib.dir/cmake_clean.cmake
.PHONY : edlib/CMakeFiles/EDLib.dir/clean

edlib/CMakeFiles/EDLib.dir/depend:
	cd /root/edlib_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/edlib_ws/src /root/edlib_ws/src/edlib /root/edlib_ws/build /root/edlib_ws/build/edlib /root/edlib_ws/build/edlib/CMakeFiles/EDLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : edlib/CMakeFiles/EDLib.dir/depend
