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
include CMakeFiles/neurosis.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/neurosis.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/neurosis.dir/flags.make

CMakeFiles/neurosis.dir/neuron.cpp.o: CMakeFiles/neurosis.dir/flags.make
CMakeFiles/neurosis.dir/neuron.cpp.o: ../neuron.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/neurosis.dir/neuron.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/neurosis.dir/neuron.cpp.o -c /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/neuron.cpp

CMakeFiles/neurosis.dir/neuron.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/neurosis.dir/neuron.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/neuron.cpp > CMakeFiles/neurosis.dir/neuron.cpp.i

CMakeFiles/neurosis.dir/neuron.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/neurosis.dir/neuron.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/neuron.cpp -o CMakeFiles/neurosis.dir/neuron.cpp.s

CMakeFiles/neurosis.dir/neuron.cpp.o.requires:
.PHONY : CMakeFiles/neurosis.dir/neuron.cpp.o.requires

CMakeFiles/neurosis.dir/neuron.cpp.o.provides: CMakeFiles/neurosis.dir/neuron.cpp.o.requires
	$(MAKE) -f CMakeFiles/neurosis.dir/build.make CMakeFiles/neurosis.dir/neuron.cpp.o.provides.build
.PHONY : CMakeFiles/neurosis.dir/neuron.cpp.o.provides

CMakeFiles/neurosis.dir/neuron.cpp.o.provides.build: CMakeFiles/neurosis.dir/neuron.cpp.o

CMakeFiles/neurosis.dir/simulation.cpp.o: CMakeFiles/neurosis.dir/flags.make
CMakeFiles/neurosis.dir/simulation.cpp.o: ../simulation.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/neurosis.dir/simulation.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/neurosis.dir/simulation.cpp.o -c /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/simulation.cpp

CMakeFiles/neurosis.dir/simulation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/neurosis.dir/simulation.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/simulation.cpp > CMakeFiles/neurosis.dir/simulation.cpp.i

CMakeFiles/neurosis.dir/simulation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/neurosis.dir/simulation.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/simulation.cpp -o CMakeFiles/neurosis.dir/simulation.cpp.s

CMakeFiles/neurosis.dir/simulation.cpp.o.requires:
.PHONY : CMakeFiles/neurosis.dir/simulation.cpp.o.requires

CMakeFiles/neurosis.dir/simulation.cpp.o.provides: CMakeFiles/neurosis.dir/simulation.cpp.o.requires
	$(MAKE) -f CMakeFiles/neurosis.dir/build.make CMakeFiles/neurosis.dir/simulation.cpp.o.provides.build
.PHONY : CMakeFiles/neurosis.dir/simulation.cpp.o.provides

CMakeFiles/neurosis.dir/simulation.cpp.o.provides.build: CMakeFiles/neurosis.dir/simulation.cpp.o

CMakeFiles/neurosis.dir/main.cpp.o: CMakeFiles/neurosis.dir/flags.make
CMakeFiles/neurosis.dir/main.cpp.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/neurosis.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/neurosis.dir/main.cpp.o -c /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/main.cpp

CMakeFiles/neurosis.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/neurosis.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/main.cpp > CMakeFiles/neurosis.dir/main.cpp.i

CMakeFiles/neurosis.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/neurosis.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/main.cpp -o CMakeFiles/neurosis.dir/main.cpp.s

CMakeFiles/neurosis.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/neurosis.dir/main.cpp.o.requires

CMakeFiles/neurosis.dir/main.cpp.o.provides: CMakeFiles/neurosis.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/neurosis.dir/build.make CMakeFiles/neurosis.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/neurosis.dir/main.cpp.o.provides

CMakeFiles/neurosis.dir/main.cpp.o.provides.build: CMakeFiles/neurosis.dir/main.cpp.o

CMakeFiles/neurosis.dir/network.cpp.o: CMakeFiles/neurosis.dir/flags.make
CMakeFiles/neurosis.dir/network.cpp.o: ../network.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/neurosis.dir/network.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/neurosis.dir/network.cpp.o -c /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/network.cpp

CMakeFiles/neurosis.dir/network.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/neurosis.dir/network.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/network.cpp > CMakeFiles/neurosis.dir/network.cpp.i

CMakeFiles/neurosis.dir/network.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/neurosis.dir/network.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/network.cpp -o CMakeFiles/neurosis.dir/network.cpp.s

CMakeFiles/neurosis.dir/network.cpp.o.requires:
.PHONY : CMakeFiles/neurosis.dir/network.cpp.o.requires

CMakeFiles/neurosis.dir/network.cpp.o.provides: CMakeFiles/neurosis.dir/network.cpp.o.requires
	$(MAKE) -f CMakeFiles/neurosis.dir/build.make CMakeFiles/neurosis.dir/network.cpp.o.provides.build
.PHONY : CMakeFiles/neurosis.dir/network.cpp.o.provides

CMakeFiles/neurosis.dir/network.cpp.o.provides.build: CMakeFiles/neurosis.dir/network.cpp.o

# Object files for target neurosis
neurosis_OBJECTS = \
"CMakeFiles/neurosis.dir/neuron.cpp.o" \
"CMakeFiles/neurosis.dir/simulation.cpp.o" \
"CMakeFiles/neurosis.dir/main.cpp.o" \
"CMakeFiles/neurosis.dir/network.cpp.o"

# External object files for target neurosis
neurosis_EXTERNAL_OBJECTS =

neurosis: CMakeFiles/neurosis.dir/neuron.cpp.o
neurosis: CMakeFiles/neurosis.dir/simulation.cpp.o
neurosis: CMakeFiles/neurosis.dir/main.cpp.o
neurosis: CMakeFiles/neurosis.dir/network.cpp.o
neurosis: CMakeFiles/neurosis.dir/build.make
neurosis: CMakeFiles/neurosis.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable neurosis"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/neurosis.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/neurosis.dir/build: neurosis
.PHONY : CMakeFiles/neurosis.dir/build

CMakeFiles/neurosis.dir/requires: CMakeFiles/neurosis.dir/neuron.cpp.o.requires
CMakeFiles/neurosis.dir/requires: CMakeFiles/neurosis.dir/simulation.cpp.o.requires
CMakeFiles/neurosis.dir/requires: CMakeFiles/neurosis.dir/main.cpp.o.requires
CMakeFiles/neurosis.dir/requires: CMakeFiles/neurosis.dir/network.cpp.o.requires
.PHONY : CMakeFiles/neurosis.dir/requires

CMakeFiles/neurosis.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/neurosis.dir/cmake_clean.cmake
.PHONY : CMakeFiles/neurosis.dir/clean

CMakeFiles/neurosis.dir/depend:
	cd /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/build /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/build /home/INTRANET/fokasand/myfiles/cpp/BA3/project/neurosis/build/CMakeFiles/neurosis.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/neurosis.dir/depend

