# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/alemh/Documents/MasterCS/GRAFPICA/FINAL/VIRTUAL_REALITY_VIDEOS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alemh/Documents/MasterCS/GRAFPICA/FINAL/VIRTUAL_REALITY_VIDEOS

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/alemh/Documents/MasterCS/GRAFPICA/FINAL/VIRTUAL_REALITY_VIDEOS/CMakeFiles /home/alemh/Documents/MasterCS/GRAFPICA/FINAL/VIRTUAL_REALITY_VIDEOS/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/alemh/Documents/MasterCS/GRAFPICA/FINAL/VIRTUAL_REALITY_VIDEOS/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named coordinate_system

# Build rule for target.
coordinate_system: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 coordinate_system
.PHONY : coordinate_system

# fast build rule for target.
coordinate_system/fast:
	$(MAKE) -f CMakeFiles/coordinate_system.dir/build.make CMakeFiles/coordinate_system.dir/build
.PHONY : coordinate_system/fast

coordinate_system.o: coordinate_system.cpp.o
.PHONY : coordinate_system.o

# target to build an object file
coordinate_system.cpp.o:
	$(MAKE) -f CMakeFiles/coordinate_system.dir/build.make CMakeFiles/coordinate_system.dir/coordinate_system.cpp.o
.PHONY : coordinate_system.cpp.o

coordinate_system.i: coordinate_system.cpp.i
.PHONY : coordinate_system.i

# target to preprocess a source file
coordinate_system.cpp.i:
	$(MAKE) -f CMakeFiles/coordinate_system.dir/build.make CMakeFiles/coordinate_system.dir/coordinate_system.cpp.i
.PHONY : coordinate_system.cpp.i

coordinate_system.s: coordinate_system.cpp.s
.PHONY : coordinate_system.s

# target to generate assembly for a file
coordinate_system.cpp.s:
	$(MAKE) -f CMakeFiles/coordinate_system.dir/build.make CMakeFiles/coordinate_system.dir/coordinate_system.cpp.s
.PHONY : coordinate_system.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... coordinate_system"
	@echo "... coordinate_system.o"
	@echo "... coordinate_system.i"
	@echo "... coordinate_system.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

