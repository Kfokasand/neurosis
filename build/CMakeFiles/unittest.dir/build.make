# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/build

# Include any dependencies generated for this target.
include CMakeFiles/unittest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/unittest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/unittest.dir/flags.make

CMakeFiles/unittest.dir/neuron.cpp.o: CMakeFiles/unittest.dir/flags.make
CMakeFiles/unittest.dir/neuron.cpp.o: ../neuron.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/unittest.dir/neuron.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/unittest.dir/neuron.cpp.o -c /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/neuron.cpp

CMakeFiles/unittest.dir/neuron.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unittest.dir/neuron.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/neuron.cpp > CMakeFiles/unittest.dir/neuron.cpp.i

CMakeFiles/unittest.dir/neuron.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unittest.dir/neuron.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/neuron.cpp -o CMakeFiles/unittest.dir/neuron.cpp.s

CMakeFiles/unittest.dir/neuron.cpp.o.requires:
.PHONY : CMakeFiles/unittest.dir/neuron.cpp.o.requires

CMakeFiles/unittest.dir/neuron.cpp.o.provides: CMakeFiles/unittest.dir/neuron.cpp.o.requires
	$(MAKE) -f CMakeFiles/unittest.dir/build.make CMakeFiles/unittest.dir/neuron.cpp.o.provides.build
.PHONY : CMakeFiles/unittest.dir/neuron.cpp.o.provides

CMakeFiles/unittest.dir/neuron.cpp.o.provides.build: CMakeFiles/unittest.dir/neuron.cpp.o

CMakeFiles/unittest.dir/simulation.cpp.o: CMakeFiles/unittest.dir/flags.make
CMakeFiles/unittest.dir/simulation.cpp.o: ../simulation.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/unittest.dir/simulation.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/unittest.dir/simulation.cpp.o -c /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/simulation.cpp

CMakeFiles/unittest.dir/simulation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unittest.dir/simulation.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/simulation.cpp > CMakeFiles/unittest.dir/simulation.cpp.i

CMakeFiles/unittest.dir/simulation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unittest.dir/simulation.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/simulation.cpp -o CMakeFiles/unittest.dir/simulation.cpp.s

CMakeFiles/unittest.dir/simulation.cpp.o.requires:
.PHONY : CMakeFiles/unittest.dir/simulation.cpp.o.requires

CMakeFiles/unittest.dir/simulation.cpp.o.provides: CMakeFiles/unittest.dir/simulation.cpp.o.requires
	$(MAKE) -f CMakeFiles/unittest.dir/build.make CMakeFiles/unittest.dir/simulation.cpp.o.provides.build
.PHONY : CMakeFiles/unittest.dir/simulation.cpp.o.provides

CMakeFiles/unittest.dir/simulation.cpp.o.provides.build: CMakeFiles/unittest.dir/simulation.cpp.o

CMakeFiles/unittest.dir/network.cpp.o: CMakeFiles/unittest.dir/flags.make
CMakeFiles/unittest.dir/network.cpp.o: ../network.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/unittest.dir/network.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/unittest.dir/network.cpp.o -c /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/network.cpp

CMakeFiles/unittest.dir/network.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unittest.dir/network.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/network.cpp > CMakeFiles/unittest.dir/network.cpp.i

CMakeFiles/unittest.dir/network.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unittest.dir/network.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/network.cpp -o CMakeFiles/unittest.dir/network.cpp.s

CMakeFiles/unittest.dir/network.cpp.o.requires:
.PHONY : CMakeFiles/unittest.dir/network.cpp.o.requires

CMakeFiles/unittest.dir/network.cpp.o.provides: CMakeFiles/unittest.dir/network.cpp.o.requires
	$(MAKE) -f CMakeFiles/unittest.dir/build.make CMakeFiles/unittest.dir/network.cpp.o.provides.build
.PHONY : CMakeFiles/unittest.dir/network.cpp.o.provides

CMakeFiles/unittest.dir/network.cpp.o.provides.build: CMakeFiles/unittest.dir/network.cpp.o

# Object files for target unittest
unittest_OBJECTS = \
"CMakeFiles/unittest.dir/neuron.cpp.o" \
"CMakeFiles/unittest.dir/simulation.cpp.o" \
"CMakeFiles/unittest.dir/network.cpp.o"

# External object files for target unittest
unittest_EXTERNAL_OBJECTS =

unittest: CMakeFiles/unittest.dir/neuron.cpp.o
unittest: CMakeFiles/unittest.dir/simulation.cpp.o
unittest: CMakeFiles/unittest.dir/network.cpp.o
unittest: CMakeFiles/unittest.dir/build.make
unittest: googletest/libgtest.a
unittest: googletest/libgtest_main.a
unittest: googletest/libgtest.a
unittest: CMakeFiles/unittest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable unittest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unittest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/unittest.dir/build: unittest
.PHONY : CMakeFiles/unittest.dir/build

CMakeFiles/unittest.dir/requires: CMakeFiles/unittest.dir/neuron.cpp.o.requires
CMakeFiles/unittest.dir/requires: CMakeFiles/unittest.dir/simulation.cpp.o.requires
CMakeFiles/unittest.dir/requires: CMakeFiles/unittest.dir/network.cpp.o.requires
.PHONY : CMakeFiles/unittest.dir/requires

CMakeFiles/unittest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/unittest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/unittest.dir/clean

CMakeFiles/unittest.dir/depend:
	cd /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/build /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/build /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/build/CMakeFiles/unittest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/unittest.dir/depend

