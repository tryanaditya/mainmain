if (NOT PYTHON_BASENAME)
    message(STATUS "Using default python: .cpython-35m-x86_64-linux-gnu")
    SET(PYTHON_BASENAME .cpython-35m-x86_64-linux-gnu)
endif()
include(/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/cmake/PySide-1.2.4/PySideConfig${PYTHON_BASENAME}.cmake)
