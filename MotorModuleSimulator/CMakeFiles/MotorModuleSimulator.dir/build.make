# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator

# Include any dependencies generated for this target.
include CMakeFiles/MotorModuleSimulator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MotorModuleSimulator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MotorModuleSimulator.dir/flags.make

CMakeFiles/MotorModuleSimulator.dir/main.cpp.o: CMakeFiles/MotorModuleSimulator.dir/flags.make
CMakeFiles/MotorModuleSimulator.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MotorModuleSimulator.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MotorModuleSimulator.dir/main.cpp.o -c /home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator/main.cpp

CMakeFiles/MotorModuleSimulator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MotorModuleSimulator.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator/main.cpp > CMakeFiles/MotorModuleSimulator.dir/main.cpp.i

CMakeFiles/MotorModuleSimulator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MotorModuleSimulator.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator/main.cpp -o CMakeFiles/MotorModuleSimulator.dir/main.cpp.s

CMakeFiles/MotorModuleSimulator.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/MotorModuleSimulator.dir/main.cpp.o.requires

CMakeFiles/MotorModuleSimulator.dir/main.cpp.o.provides: CMakeFiles/MotorModuleSimulator.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/MotorModuleSimulator.dir/build.make CMakeFiles/MotorModuleSimulator.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/MotorModuleSimulator.dir/main.cpp.o.provides

CMakeFiles/MotorModuleSimulator.dir/main.cpp.o.provides.build: CMakeFiles/MotorModuleSimulator.dir/main.cpp.o


CMakeFiles/MotorModuleSimulator.dir/Controller.cpp.o: CMakeFiles/MotorModuleSimulator.dir/flags.make
CMakeFiles/MotorModuleSimulator.dir/Controller.cpp.o: Controller.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MotorModuleSimulator.dir/Controller.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MotorModuleSimulator.dir/Controller.cpp.o -c /home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator/Controller.cpp

CMakeFiles/MotorModuleSimulator.dir/Controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MotorModuleSimulator.dir/Controller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator/Controller.cpp > CMakeFiles/MotorModuleSimulator.dir/Controller.cpp.i

CMakeFiles/MotorModuleSimulator.dir/Controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MotorModuleSimulator.dir/Controller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator/Controller.cpp -o CMakeFiles/MotorModuleSimulator.dir/Controller.cpp.s

CMakeFiles/MotorModuleSimulator.dir/Controller.cpp.o.requires:

.PHONY : CMakeFiles/MotorModuleSimulator.dir/Controller.cpp.o.requires

CMakeFiles/MotorModuleSimulator.dir/Controller.cpp.o.provides: CMakeFiles/MotorModuleSimulator.dir/Controller.cpp.o.requires
	$(MAKE) -f CMakeFiles/MotorModuleSimulator.dir/build.make CMakeFiles/MotorModuleSimulator.dir/Controller.cpp.o.provides.build
.PHONY : CMakeFiles/MotorModuleSimulator.dir/Controller.cpp.o.provides

CMakeFiles/MotorModuleSimulator.dir/Controller.cpp.o.provides.build: CMakeFiles/MotorModuleSimulator.dir/Controller.cpp.o


CMakeFiles/MotorModuleSimulator.dir/RS485/SerialPort.cpp.o: CMakeFiles/MotorModuleSimulator.dir/flags.make
CMakeFiles/MotorModuleSimulator.dir/RS485/SerialPort.cpp.o: RS485/SerialPort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MotorModuleSimulator.dir/RS485/SerialPort.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MotorModuleSimulator.dir/RS485/SerialPort.cpp.o -c /home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator/RS485/SerialPort.cpp

CMakeFiles/MotorModuleSimulator.dir/RS485/SerialPort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MotorModuleSimulator.dir/RS485/SerialPort.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator/RS485/SerialPort.cpp > CMakeFiles/MotorModuleSimulator.dir/RS485/SerialPort.cpp.i

CMakeFiles/MotorModuleSimulator.dir/RS485/SerialPort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MotorModuleSimulator.dir/RS485/SerialPort.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator/RS485/SerialPort.cpp -o CMakeFiles/MotorModuleSimulator.dir/RS485/SerialPort.cpp.s

CMakeFiles/MotorModuleSimulator.dir/RS485/SerialPort.cpp.o.requires:

.PHONY : CMakeFiles/MotorModuleSimulator.dir/RS485/SerialPort.cpp.o.requires

CMakeFiles/MotorModuleSimulator.dir/RS485/SerialPort.cpp.o.provides: CMakeFiles/MotorModuleSimulator.dir/RS485/SerialPort.cpp.o.requires
	$(MAKE) -f CMakeFiles/MotorModuleSimulator.dir/build.make CMakeFiles/MotorModuleSimulator.dir/RS485/SerialPort.cpp.o.provides.build
.PHONY : CMakeFiles/MotorModuleSimulator.dir/RS485/SerialPort.cpp.o.provides

CMakeFiles/MotorModuleSimulator.dir/RS485/SerialPort.cpp.o.provides.build: CMakeFiles/MotorModuleSimulator.dir/RS485/SerialPort.cpp.o


CMakeFiles/MotorModuleSimulator.dir/RS485/CommunicationHandler.cpp.o: CMakeFiles/MotorModuleSimulator.dir/flags.make
CMakeFiles/MotorModuleSimulator.dir/RS485/CommunicationHandler.cpp.o: RS485/CommunicationHandler.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/MotorModuleSimulator.dir/RS485/CommunicationHandler.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MotorModuleSimulator.dir/RS485/CommunicationHandler.cpp.o -c /home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator/RS485/CommunicationHandler.cpp

CMakeFiles/MotorModuleSimulator.dir/RS485/CommunicationHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MotorModuleSimulator.dir/RS485/CommunicationHandler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator/RS485/CommunicationHandler.cpp > CMakeFiles/MotorModuleSimulator.dir/RS485/CommunicationHandler.cpp.i

CMakeFiles/MotorModuleSimulator.dir/RS485/CommunicationHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MotorModuleSimulator.dir/RS485/CommunicationHandler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator/RS485/CommunicationHandler.cpp -o CMakeFiles/MotorModuleSimulator.dir/RS485/CommunicationHandler.cpp.s

CMakeFiles/MotorModuleSimulator.dir/RS485/CommunicationHandler.cpp.o.requires:

.PHONY : CMakeFiles/MotorModuleSimulator.dir/RS485/CommunicationHandler.cpp.o.requires

CMakeFiles/MotorModuleSimulator.dir/RS485/CommunicationHandler.cpp.o.provides: CMakeFiles/MotorModuleSimulator.dir/RS485/CommunicationHandler.cpp.o.requires
	$(MAKE) -f CMakeFiles/MotorModuleSimulator.dir/build.make CMakeFiles/MotorModuleSimulator.dir/RS485/CommunicationHandler.cpp.o.provides.build
.PHONY : CMakeFiles/MotorModuleSimulator.dir/RS485/CommunicationHandler.cpp.o.provides

CMakeFiles/MotorModuleSimulator.dir/RS485/CommunicationHandler.cpp.o.provides.build: CMakeFiles/MotorModuleSimulator.dir/RS485/CommunicationHandler.cpp.o


CMakeFiles/MotorModuleSimulator.dir/MotorModule.cpp.o: CMakeFiles/MotorModuleSimulator.dir/flags.make
CMakeFiles/MotorModuleSimulator.dir/MotorModule.cpp.o: MotorModule.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/MotorModuleSimulator.dir/MotorModule.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MotorModuleSimulator.dir/MotorModule.cpp.o -c /home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator/MotorModule.cpp

CMakeFiles/MotorModuleSimulator.dir/MotorModule.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MotorModuleSimulator.dir/MotorModule.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator/MotorModule.cpp > CMakeFiles/MotorModuleSimulator.dir/MotorModule.cpp.i

CMakeFiles/MotorModuleSimulator.dir/MotorModule.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MotorModuleSimulator.dir/MotorModule.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator/MotorModule.cpp -o CMakeFiles/MotorModuleSimulator.dir/MotorModule.cpp.s

CMakeFiles/MotorModuleSimulator.dir/MotorModule.cpp.o.requires:

.PHONY : CMakeFiles/MotorModuleSimulator.dir/MotorModule.cpp.o.requires

CMakeFiles/MotorModuleSimulator.dir/MotorModule.cpp.o.provides: CMakeFiles/MotorModuleSimulator.dir/MotorModule.cpp.o.requires
	$(MAKE) -f CMakeFiles/MotorModuleSimulator.dir/build.make CMakeFiles/MotorModuleSimulator.dir/MotorModule.cpp.o.provides.build
.PHONY : CMakeFiles/MotorModuleSimulator.dir/MotorModule.cpp.o.provides

CMakeFiles/MotorModuleSimulator.dir/MotorModule.cpp.o.provides.build: CMakeFiles/MotorModuleSimulator.dir/MotorModule.cpp.o


# Object files for target MotorModuleSimulator
MotorModuleSimulator_OBJECTS = \
"CMakeFiles/MotorModuleSimulator.dir/main.cpp.o" \
"CMakeFiles/MotorModuleSimulator.dir/Controller.cpp.o" \
"CMakeFiles/MotorModuleSimulator.dir/RS485/SerialPort.cpp.o" \
"CMakeFiles/MotorModuleSimulator.dir/RS485/CommunicationHandler.cpp.o" \
"CMakeFiles/MotorModuleSimulator.dir/MotorModule.cpp.o"

# External object files for target MotorModuleSimulator
MotorModuleSimulator_EXTERNAL_OBJECTS =

MotorModuleSimulator: CMakeFiles/MotorModuleSimulator.dir/main.cpp.o
MotorModuleSimulator: CMakeFiles/MotorModuleSimulator.dir/Controller.cpp.o
MotorModuleSimulator: CMakeFiles/MotorModuleSimulator.dir/RS485/SerialPort.cpp.o
MotorModuleSimulator: CMakeFiles/MotorModuleSimulator.dir/RS485/CommunicationHandler.cpp.o
MotorModuleSimulator: CMakeFiles/MotorModuleSimulator.dir/MotorModule.cpp.o
MotorModuleSimulator: CMakeFiles/MotorModuleSimulator.dir/build.make
MotorModuleSimulator: CMakeFiles/MotorModuleSimulator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable MotorModuleSimulator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MotorModuleSimulator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MotorModuleSimulator.dir/build: MotorModuleSimulator

.PHONY : CMakeFiles/MotorModuleSimulator.dir/build

CMakeFiles/MotorModuleSimulator.dir/requires: CMakeFiles/MotorModuleSimulator.dir/main.cpp.o.requires
CMakeFiles/MotorModuleSimulator.dir/requires: CMakeFiles/MotorModuleSimulator.dir/Controller.cpp.o.requires
CMakeFiles/MotorModuleSimulator.dir/requires: CMakeFiles/MotorModuleSimulator.dir/RS485/SerialPort.cpp.o.requires
CMakeFiles/MotorModuleSimulator.dir/requires: CMakeFiles/MotorModuleSimulator.dir/RS485/CommunicationHandler.cpp.o.requires
CMakeFiles/MotorModuleSimulator.dir/requires: CMakeFiles/MotorModuleSimulator.dir/MotorModule.cpp.o.requires

.PHONY : CMakeFiles/MotorModuleSimulator.dir/requires

CMakeFiles/MotorModuleSimulator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MotorModuleSimulator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MotorModuleSimulator.dir/clean

CMakeFiles/MotorModuleSimulator.dir/depend:
	cd /home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator /home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator /home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator /home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator /home/stefan/projects/school/positioningRig/PosiControl/MotorModuleSimulator/CMakeFiles/MotorModuleSimulator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MotorModuleSimulator.dir/depend

