# Install script for directory: /root/pyside/PySide-1.2.4/sources/shiboken/libshiboken

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "Release")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "0")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/shiboken" TYPE FILE FILES
    "/root/pyside/PySide-1.2.4/sources/shiboken/libshiboken/autodecref.h"
    "/root/pyside/PySide-1.2.4/sources/shiboken/libshiboken/basewrapper.h"
    "/root/pyside/PySide-1.2.4/sources/shiboken/libshiboken/bindingmanager.h"
    "/root/pyside/PySide-1.2.4/sources/shiboken/libshiboken/conversions.h"
    "/root/pyside/PySide-1.2.4/sources/shiboken/libshiboken/gilstate.h"
    "/root/pyside/PySide-1.2.4/sources/shiboken/libshiboken/helper.h"
    "/root/pyside/PySide-1.2.4/sources/shiboken/libshiboken/sbkconverter.h"
    "/root/pyside/PySide-1.2.4/sources/shiboken/libshiboken/sbkenum.h"
    "/root/pyside/PySide-1.2.4/sources/shiboken/libshiboken/sbkmodule.h"
    "/root/pyside/PySide-1.2.4/sources/shiboken/libshiboken/python25compat.h"
    "/root/pyside/PySide-1.2.4/sources/shiboken/libshiboken/sbkdbg.h"
    "/root/pyside/PySide-1.2.4/sources/shiboken/libshiboken/sbkstring.h"
    "/root/pyside/PySide-1.2.4/sources/shiboken/libshiboken/shiboken.h"
    "/root/pyside/PySide-1.2.4/sources/shiboken/libshiboken/shibokenmacros.h"
    "/root/pyside/PySide-1.2.4/sources/shiboken/libshiboken/threadstatesaver.h"
    "/root/pyside/PySide-1.2.4/sources/shiboken/libshiboken/typeresolver.h"
    "/root/pyside/PySide-1.2.4/sources/shiboken/libshiboken/shibokenbuffer.h"
    "/root/pyside/PySide-1.2.4/sources/shiboken/libshiboken/sbkpython.h"
    "/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/shiboken/libshiboken/sbkversion.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FOREACH(file
      "$ENV{DESTDIR}/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/libshiboken.cpython-35m-x86_64-linux-gnu.so.1.2.4"
      "$ENV{DESTDIR}/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/libshiboken.cpython-35m-x86_64-linux-gnu.so.1.2"
      "$ENV{DESTDIR}/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/libshiboken.cpython-35m-x86_64-linux-gnu.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      FILE(RPATH_CHECK
           FILE "${file}"
           RPATH "/usr/local/lib")
    ENDIF()
  ENDFOREACH()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/libshiboken.cpython-35m-x86_64-linux-gnu.so.1.2.4;/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/libshiboken.cpython-35m-x86_64-linux-gnu.so.1.2;/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/libshiboken.cpython-35m-x86_64-linux-gnu.so")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib" TYPE SHARED_LIBRARY FILES
    "/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/shiboken/libshiboken/libshiboken.cpython-35m-x86_64-linux-gnu.so.1.2.4"
    "/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/shiboken/libshiboken/libshiboken.cpython-35m-x86_64-linux-gnu.so.1.2"
    "/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/shiboken/libshiboken/libshiboken.cpython-35m-x86_64-linux-gnu.so"
    )
  FOREACH(file
      "$ENV{DESTDIR}/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/libshiboken.cpython-35m-x86_64-linux-gnu.so.1.2.4"
      "$ENV{DESTDIR}/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/libshiboken.cpython-35m-x86_64-linux-gnu.so.1.2"
      "$ENV{DESTDIR}/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/libshiboken.cpython-35m-x86_64-linux-gnu.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      FILE(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/usr/local/lib:"
           NEW_RPATH "/usr/local/lib")
      IF(CMAKE_INSTALL_DO_STRIP)
        EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
      ENDIF(CMAKE_INSTALL_DO_STRIP)
    ENDIF()
  ENDFOREACH()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

