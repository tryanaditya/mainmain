#  SHIBOKEN_INCLUDE_DIR        - Directories to include to use SHIBOKEN
#  SHIBOKEN_LIBRARY            - Files to link against to use SHIBOKEN
#  SHIBOKEN_BINARY             - Executable name
#  SHIBOKEN_BUILD_TYPE         - Tells if Shiboken was compiled in Release or Debug mode.
#  SHIBOKEN_PYTHON_INTERPRETER - Python interpreter (regular or debug) to be used with the bindings.
#  SHIBOKEN_PYTHON_LIBRARIES   - Python libraries (regular or debug) Shiboken is linked against.

SET(SHIBOKEN_INCLUDE_DIR "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/include/shiboken")
if(MSVC)
    SET(SHIBOKEN_LIBRARY "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/libshiboken.cpython-35m-x86_64-linux-gnu.lib")
elseif(CYGWIN)
    SET(SHIBOKEN_LIBRARY "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/shiboken.cpython-35m-x86_64-linux-gnu")
elseif(WIN32)
    SET(SHIBOKEN_LIBRARY "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/bin/libshiboken.cpython-35m-x86_64-linux-gnu.so")
else()
    SET(SHIBOKEN_LIBRARY "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/libshiboken.cpython-35m-x86_64-linux-gnu.so")
endif()
SET(SHIBOKEN_PYTHON_INCLUDE_DIR "/usr/local/include/python3.5m")
SET(SHIBOKEN_PYTHON_INCLUDE_DIR "/usr/local/include/python3.5m")
SET(SHIBOKEN_PYTHON_INTERPRETER "/usr/local/bin/python3")
SET(SHIBOKEN_PYTHON_LIBRARIES "/usr/local/lib/libpython3.5m.so")
SET(SHIBOKEN_PYTHON_SUFFIX ".cpython-35m-x86_64-linux-gnu")
message(STATUS "libshiboken built for Release")


set(SHIBOKEN_BINARY "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/bin/shiboken")
