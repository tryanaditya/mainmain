# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/pyside/PySide-1.2.4/sources/shiboken

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/shiboken

# Utility rule file for data.

# Include the progress variables for this target.
include data/CMakeFiles/data.dir/progress.make

data/CMakeFiles/data:

data: data/CMakeFiles/data
data: data/CMakeFiles/data.dir/build.make
.PHONY : data

# Rule to build all files generated by this target.
data/CMakeFiles/data.dir/build: data
.PHONY : data/CMakeFiles/data.dir/build

data/CMakeFiles/data.dir/clean:
	cd /root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/shiboken/data && $(CMAKE_COMMAND) -P CMakeFiles/data.dir/cmake_clean.cmake
.PHONY : data/CMakeFiles/data.dir/clean

data/CMakeFiles/data.dir/depend:
	cd /root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/shiboken && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/pyside/PySide-1.2.4/sources/shiboken /root/pyside/PySide-1.2.4/sources/shiboken/data /root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/shiboken /root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/shiboken/data /root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/shiboken/data/CMakeFiles/data.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : data/CMakeFiles/data.dir/depend

