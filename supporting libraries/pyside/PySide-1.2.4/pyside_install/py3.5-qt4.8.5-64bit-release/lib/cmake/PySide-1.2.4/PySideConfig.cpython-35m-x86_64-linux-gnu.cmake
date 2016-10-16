#  PYSIDE_INCLUDE_DIR   - Directories to include to use PySide
#  PYSIDE_LIBRARY       - Files to link against to use PySide
#  PYSIDE_PYTHONPATH    - Path to where the PySide Python module files could be found
#  PYSIDE_TYPESYSTEMS   - Type system files that should be used by other bindings extending PySide

SET(PYSIDE_INCLUDE_DIR "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/include/PySide")
# Platform specific library names
if(MSVC)
    SET(PYSIDE_LIBRARY "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/libpyside.cpython-35m-x86_64-linux-gnu.lib")
elseif(CYGWIN)
    SET(PYSIDE_LIBRARY "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/libpyside.cpython-35m-x86_64-linux-gnu")
elseif(WIN32)
    SET(PYSIDE_LIBRARY "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/bin/libpyside.cpython-35m-x86_64-linux-gnu.so")
else()
    SET(PYSIDE_LIBRARY "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/libpyside.cpython-35m-x86_64-linux-gnu.so")
endif()
SET(PYSIDE_PYTHONPATH "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/python3.5/site-packages")
SET(PYSIDE_TYPESYSTEMS "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/share/PySide/typesystems")
