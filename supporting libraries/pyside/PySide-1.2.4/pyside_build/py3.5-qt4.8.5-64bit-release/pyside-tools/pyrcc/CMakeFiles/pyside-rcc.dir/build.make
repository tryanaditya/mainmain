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
CMAKE_SOURCE_DIR = /root/pyside/PySide-1.2.4/sources/pyside-tools

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside-tools

# Include any dependencies generated for this target.
include pyrcc/CMakeFiles/pyside-rcc.dir/depend.make

# Include the progress variables for this target.
include pyrcc/CMakeFiles/pyside-rcc.dir/progress.make

# Include the compile flags for this target's objects.
include pyrcc/CMakeFiles/pyside-rcc.dir/flags.make

pyrcc/CMakeFiles/pyside-rcc.dir/main.cpp.o: pyrcc/CMakeFiles/pyside-rcc.dir/flags.make
pyrcc/CMakeFiles/pyside-rcc.dir/main.cpp.o: /root/pyside/PySide-1.2.4/sources/pyside-tools/pyrcc/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside-tools/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object pyrcc/CMakeFiles/pyside-rcc.dir/main.cpp.o"
	cd /root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside-tools/pyrcc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/pyside-rcc.dir/main.cpp.o -c /root/pyside/PySide-1.2.4/sources/pyside-tools/pyrcc/main.cpp

pyrcc/CMakeFiles/pyside-rcc.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pyside-rcc.dir/main.cpp.i"
	cd /root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside-tools/pyrcc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/pyside/PySide-1.2.4/sources/pyside-tools/pyrcc/main.cpp > CMakeFiles/pyside-rcc.dir/main.cpp.i

pyrcc/CMakeFiles/pyside-rcc.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pyside-rcc.dir/main.cpp.s"
	cd /root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside-tools/pyrcc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/pyside/PySide-1.2.4/sources/pyside-tools/pyrcc/main.cpp -o CMakeFiles/pyside-rcc.dir/main.cpp.s

pyrcc/CMakeFiles/pyside-rcc.dir/main.cpp.o.requires:
.PHONY : pyrcc/CMakeFiles/pyside-rcc.dir/main.cpp.o.requires

pyrcc/CMakeFiles/pyside-rcc.dir/main.cpp.o.provides: pyrcc/CMakeFiles/pyside-rcc.dir/main.cpp.o.requires
	$(MAKE) -f pyrcc/CMakeFiles/pyside-rcc.dir/build.make pyrcc/CMakeFiles/pyside-rcc.dir/main.cpp.o.provides.build
.PHONY : pyrcc/CMakeFiles/pyside-rcc.dir/main.cpp.o.provides

pyrcc/CMakeFiles/pyside-rcc.dir/main.cpp.o.provides.build: pyrcc/CMakeFiles/pyside-rcc.dir/main.cpp.o

pyrcc/CMakeFiles/pyside-rcc.dir/rcc.cpp.o: pyrcc/CMakeFiles/pyside-rcc.dir/flags.make
pyrcc/CMakeFiles/pyside-rcc.dir/rcc.cpp.o: /root/pyside/PySide-1.2.4/sources/pyside-tools/pyrcc/rcc.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside-tools/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object pyrcc/CMakeFiles/pyside-rcc.dir/rcc.cpp.o"
	cd /root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside-tools/pyrcc && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/pyside-rcc.dir/rcc.cpp.o -c /root/pyside/PySide-1.2.4/sources/pyside-tools/pyrcc/rcc.cpp

pyrcc/CMakeFiles/pyside-rcc.dir/rcc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pyside-rcc.dir/rcc.cpp.i"
	cd /root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside-tools/pyrcc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /root/pyside/PySide-1.2.4/sources/pyside-tools/pyrcc/rcc.cpp > CMakeFiles/pyside-rcc.dir/rcc.cpp.i

pyrcc/CMakeFiles/pyside-rcc.dir/rcc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pyside-rcc.dir/rcc.cpp.s"
	cd /root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside-tools/pyrcc && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /root/pyside/PySide-1.2.4/sources/pyside-tools/pyrcc/rcc.cpp -o CMakeFiles/pyside-rcc.dir/rcc.cpp.s

pyrcc/CMakeFiles/pyside-rcc.dir/rcc.cpp.o.requires:
.PHONY : pyrcc/CMakeFiles/pyside-rcc.dir/rcc.cpp.o.requires

pyrcc/CMakeFiles/pyside-rcc.dir/rcc.cpp.o.provides: pyrcc/CMakeFiles/pyside-rcc.dir/rcc.cpp.o.requires
	$(MAKE) -f pyrcc/CMakeFiles/pyside-rcc.dir/build.make pyrcc/CMakeFiles/pyside-rcc.dir/rcc.cpp.o.provides.build
.PHONY : pyrcc/CMakeFiles/pyside-rcc.dir/rcc.cpp.o.provides

pyrcc/CMakeFiles/pyside-rcc.dir/rcc.cpp.o.provides.build: pyrcc/CMakeFiles/pyside-rcc.dir/rcc.cpp.o

# Object files for target pyside-rcc
pyside__rcc_OBJECTS = \
"CMakeFiles/pyside-rcc.dir/main.cpp.o" \
"CMakeFiles/pyside-rcc.dir/rcc.cpp.o"

# External object files for target pyside-rcc
pyside__rcc_EXTERNAL_OBJECTS =

pyrcc/pyside-rcc: pyrcc/CMakeFiles/pyside-rcc.dir/main.cpp.o
pyrcc/pyside-rcc: pyrcc/CMakeFiles/pyside-rcc.dir/rcc.cpp.o
pyrcc/pyside-rcc: pyrcc/CMakeFiles/pyside-rcc.dir/build.make
pyrcc/pyside-rcc: /usr/lib64/libQtCore.so
pyrcc/pyside-rcc: /usr/lib64/libQtXml.so
pyrcc/pyside-rcc: pyrcc/CMakeFiles/pyside-rcc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable pyside-rcc"
	cd /root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside-tools/pyrcc && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pyside-rcc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
pyrcc/CMakeFiles/pyside-rcc.dir/build: pyrcc/pyside-rcc
.PHONY : pyrcc/CMakeFiles/pyside-rcc.dir/build

pyrcc/CMakeFiles/pyside-rcc.dir/requires: pyrcc/CMakeFiles/pyside-rcc.dir/main.cpp.o.requires
pyrcc/CMakeFiles/pyside-rcc.dir/requires: pyrcc/CMakeFiles/pyside-rcc.dir/rcc.cpp.o.requires
.PHONY : pyrcc/CMakeFiles/pyside-rcc.dir/requires

pyrcc/CMakeFiles/pyside-rcc.dir/clean:
	cd /root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside-tools/pyrcc && $(CMAKE_COMMAND) -P CMakeFiles/pyside-rcc.dir/cmake_clean.cmake
.PHONY : pyrcc/CMakeFiles/pyside-rcc.dir/clean

pyrcc/CMakeFiles/pyside-rcc.dir/depend:
	cd /root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside-tools && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/pyside/PySide-1.2.4/sources/pyside-tools /root/pyside/PySide-1.2.4/sources/pyside-tools/pyrcc /root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside-tools /root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside-tools/pyrcc /root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside-tools/pyrcc/CMakeFiles/pyside-rcc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : pyrcc/CMakeFiles/pyside-rcc.dir/depend

