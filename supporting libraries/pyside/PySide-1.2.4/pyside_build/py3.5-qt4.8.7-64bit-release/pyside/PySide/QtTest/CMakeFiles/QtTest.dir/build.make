# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/pyside

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside

# Include any dependencies generated for this target.
include PySide/QtTest/CMakeFiles/QtTest.dir/depend.make

# Include the progress variables for this target.
include PySide/QtTest/CMakeFiles/QtTest.dir/progress.make

# Include the compile flags for this target's objects.
include PySide/QtTest/CMakeFiles/QtTest.dir/flags.make

PySide/QtTest/PySide/QtTest/qtest_wrapper.cpp:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running generator for QtTest..."
	cd /home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/pyside/PySide/QtTest && /home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/bin/shiboken --generator-set=shiboken --enable-parent-ctor-heuristic --enable-pyside-extensions --enable-return-value-heuristic --use-isnull-as-nb_nonzero /home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/pyside_global.h --include-paths=/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/pyside/PySide:/usr/include/qt4 --typesystem-paths=/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/pyside/PySide:/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/pyside/PySide/QtCore:/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtCore:/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/pyside/PySide/QtGui:/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtGui --output-directory=/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtTest --license-file=/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/pyside/PySide/QtTest/../licensecomment.txt /home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/pyside/PySide/QtTest/typesystem_test.xml --api-version=4.8 --drop-type-entries=""

PySide/QtTest/PySide/QtTest/qttest_module_wrapper.cpp: PySide/QtTest/PySide/QtTest/qtest_wrapper.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate PySide/QtTest/PySide/QtTest/qttest_module_wrapper.cpp

PySide/QtTest/PySide/QtTest/qtest_pysideqtoucheventsequence_wrapper.cpp: PySide/QtTest/PySide/QtTest/qtest_wrapper.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate PySide/QtTest/PySide/QtTest/qtest_pysideqtoucheventsequence_wrapper.cpp

PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_wrapper.cpp.o: PySide/QtTest/CMakeFiles/QtTest.dir/flags.make
PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_wrapper.cpp.o: PySide/QtTest/PySide/QtTest/qtest_wrapper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_wrapper.cpp.o"
	cd /home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtTest && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QtTest.dir/PySide/QtTest/qtest_wrapper.cpp.o -c /home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtTest/PySide/QtTest/qtest_wrapper.cpp

PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_wrapper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QtTest.dir/PySide/QtTest/qtest_wrapper.cpp.i"
	cd /home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtTest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtTest/PySide/QtTest/qtest_wrapper.cpp > CMakeFiles/QtTest.dir/PySide/QtTest/qtest_wrapper.cpp.i

PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_wrapper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QtTest.dir/PySide/QtTest/qtest_wrapper.cpp.s"
	cd /home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtTest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtTest/PySide/QtTest/qtest_wrapper.cpp -o CMakeFiles/QtTest.dir/PySide/QtTest/qtest_wrapper.cpp.s

PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_wrapper.cpp.o.requires:

.PHONY : PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_wrapper.cpp.o.requires

PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_wrapper.cpp.o.provides: PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_wrapper.cpp.o.requires
	$(MAKE) -f PySide/QtTest/CMakeFiles/QtTest.dir/build.make PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_wrapper.cpp.o.provides.build
.PHONY : PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_wrapper.cpp.o.provides

PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_wrapper.cpp.o.provides.build: PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_wrapper.cpp.o


PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qttest_module_wrapper.cpp.o: PySide/QtTest/CMakeFiles/QtTest.dir/flags.make
PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qttest_module_wrapper.cpp.o: PySide/QtTest/PySide/QtTest/qttest_module_wrapper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qttest_module_wrapper.cpp.o"
	cd /home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtTest && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QtTest.dir/PySide/QtTest/qttest_module_wrapper.cpp.o -c /home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtTest/PySide/QtTest/qttest_module_wrapper.cpp

PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qttest_module_wrapper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QtTest.dir/PySide/QtTest/qttest_module_wrapper.cpp.i"
	cd /home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtTest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtTest/PySide/QtTest/qttest_module_wrapper.cpp > CMakeFiles/QtTest.dir/PySide/QtTest/qttest_module_wrapper.cpp.i

PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qttest_module_wrapper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QtTest.dir/PySide/QtTest/qttest_module_wrapper.cpp.s"
	cd /home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtTest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtTest/PySide/QtTest/qttest_module_wrapper.cpp -o CMakeFiles/QtTest.dir/PySide/QtTest/qttest_module_wrapper.cpp.s

PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qttest_module_wrapper.cpp.o.requires:

.PHONY : PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qttest_module_wrapper.cpp.o.requires

PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qttest_module_wrapper.cpp.o.provides: PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qttest_module_wrapper.cpp.o.requires
	$(MAKE) -f PySide/QtTest/CMakeFiles/QtTest.dir/build.make PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qttest_module_wrapper.cpp.o.provides.build
.PHONY : PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qttest_module_wrapper.cpp.o.provides

PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qttest_module_wrapper.cpp.o.provides.build: PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qttest_module_wrapper.cpp.o


PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_pysideqtoucheventsequence_wrapper.cpp.o: PySide/QtTest/CMakeFiles/QtTest.dir/flags.make
PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_pysideqtoucheventsequence_wrapper.cpp.o: PySide/QtTest/PySide/QtTest/qtest_pysideqtoucheventsequence_wrapper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_pysideqtoucheventsequence_wrapper.cpp.o"
	cd /home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtTest && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/QtTest.dir/PySide/QtTest/qtest_pysideqtoucheventsequence_wrapper.cpp.o -c /home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtTest/PySide/QtTest/qtest_pysideqtoucheventsequence_wrapper.cpp

PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_pysideqtoucheventsequence_wrapper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/QtTest.dir/PySide/QtTest/qtest_pysideqtoucheventsequence_wrapper.cpp.i"
	cd /home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtTest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtTest/PySide/QtTest/qtest_pysideqtoucheventsequence_wrapper.cpp > CMakeFiles/QtTest.dir/PySide/QtTest/qtest_pysideqtoucheventsequence_wrapper.cpp.i

PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_pysideqtoucheventsequence_wrapper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/QtTest.dir/PySide/QtTest/qtest_pysideqtoucheventsequence_wrapper.cpp.s"
	cd /home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtTest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtTest/PySide/QtTest/qtest_pysideqtoucheventsequence_wrapper.cpp -o CMakeFiles/QtTest.dir/PySide/QtTest/qtest_pysideqtoucheventsequence_wrapper.cpp.s

PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_pysideqtoucheventsequence_wrapper.cpp.o.requires:

.PHONY : PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_pysideqtoucheventsequence_wrapper.cpp.o.requires

PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_pysideqtoucheventsequence_wrapper.cpp.o.provides: PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_pysideqtoucheventsequence_wrapper.cpp.o.requires
	$(MAKE) -f PySide/QtTest/CMakeFiles/QtTest.dir/build.make PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_pysideqtoucheventsequence_wrapper.cpp.o.provides.build
.PHONY : PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_pysideqtoucheventsequence_wrapper.cpp.o.provides

PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_pysideqtoucheventsequence_wrapper.cpp.o.provides.build: PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_pysideqtoucheventsequence_wrapper.cpp.o


# Object files for target QtTest
QtTest_OBJECTS = \
"CMakeFiles/QtTest.dir/PySide/QtTest/qtest_wrapper.cpp.o" \
"CMakeFiles/QtTest.dir/PySide/QtTest/qttest_module_wrapper.cpp.o" \
"CMakeFiles/QtTest.dir/PySide/QtTest/qtest_pysideqtoucheventsequence_wrapper.cpp.o"

# External object files for target QtTest
QtTest_EXTERNAL_OBJECTS =

PySide/QtTest.so: PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_wrapper.cpp.o
PySide/QtTest.so: PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qttest_module_wrapper.cpp.o
PySide/QtTest.so: PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_pysideqtoucheventsequence_wrapper.cpp.o
PySide/QtTest.so: PySide/QtTest/CMakeFiles/QtTest.dir/build.make
PySide/QtTest.so: libpyside/libpyside.cpython-35m-x86_64-linux-gnu.so.1.2.4
PySide/QtTest.so: /usr/lib/x86_64-linux-gnu/libpython3.5m.so
PySide/QtTest.so: /home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib/libshiboken.cpython-35m-x86_64-linux-gnu.so
PySide/QtTest.so: /usr/lib/x86_64-linux-gnu/libQtTest.so
PySide/QtTest.so: /usr/lib/x86_64-linux-gnu/libQtGui.so
PySide/QtTest.so: /usr/lib/x86_64-linux-gnu/libQtCore.so
PySide/QtTest.so: PySide/QtTest/CMakeFiles/QtTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX shared module ../QtTest.so"
	cd /home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtTest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/QtTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
PySide/QtTest/CMakeFiles/QtTest.dir/build: PySide/QtTest.so

.PHONY : PySide/QtTest/CMakeFiles/QtTest.dir/build

PySide/QtTest/CMakeFiles/QtTest.dir/requires: PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_wrapper.cpp.o.requires
PySide/QtTest/CMakeFiles/QtTest.dir/requires: PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qttest_module_wrapper.cpp.o.requires
PySide/QtTest/CMakeFiles/QtTest.dir/requires: PySide/QtTest/CMakeFiles/QtTest.dir/PySide/QtTest/qtest_pysideqtoucheventsequence_wrapper.cpp.o.requires

.PHONY : PySide/QtTest/CMakeFiles/QtTest.dir/requires

PySide/QtTest/CMakeFiles/QtTest.dir/clean:
	cd /home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtTest && $(CMAKE_COMMAND) -P CMakeFiles/QtTest.dir/cmake_clean.cmake
.PHONY : PySide/QtTest/CMakeFiles/QtTest.dir/clean

PySide/QtTest/CMakeFiles/QtTest.dir/depend: PySide/QtTest/PySide/QtTest/qtest_wrapper.cpp
PySide/QtTest/CMakeFiles/QtTest.dir/depend: PySide/QtTest/PySide/QtTest/qttest_module_wrapper.cpp
PySide/QtTest/CMakeFiles/QtTest.dir/depend: PySide/QtTest/PySide/QtTest/qtest_pysideqtoucheventsequence_wrapper.cpp
	cd /home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/pyside /home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/pyside/PySide/QtTest /home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside /home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtTest /home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtTest/CMakeFiles/QtTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : PySide/QtTest/CMakeFiles/QtTest.dir/depend

