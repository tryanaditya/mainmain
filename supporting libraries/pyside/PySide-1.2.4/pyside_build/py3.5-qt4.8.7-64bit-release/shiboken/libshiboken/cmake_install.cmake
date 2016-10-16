# Install script for directory: /home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/shiboken/libshiboken

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/shiboken" TYPE FILE FILES
    "/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/shiboken/libshiboken/autodecref.h"
    "/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/shiboken/libshiboken/basewrapper.h"
    "/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/shiboken/libshiboken/bindingmanager.h"
    "/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/shiboken/libshiboken/conversions.h"
    "/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/shiboken/libshiboken/gilstate.h"
    "/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/shiboken/libshiboken/helper.h"
    "/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/shiboken/libshiboken/sbkconverter.h"
    "/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/shiboken/libshiboken/sbkenum.h"
    "/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/shiboken/libshiboken/sbkmodule.h"
    "/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/shiboken/libshiboken/python25compat.h"
    "/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/shiboken/libshiboken/sbkdbg.h"
    "/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/shiboken/libshiboken/sbkstring.h"
    "/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/shiboken/libshiboken/shiboken.h"
    "/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/shiboken/libshiboken/shibokenmacros.h"
    "/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/shiboken/libshiboken/threadstatesaver.h"
    "/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/shiboken/libshiboken/typeresolver.h"
    "/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/shiboken/libshiboken/shibokenbuffer.h"
    "/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/shiboken/libshiboken/sbkpython.h"
    "/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/shiboken/libshiboken/sbkversion.h"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  foreach(file
      "$ENV{DESTDIR}/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib/libshiboken.cpython-35m-x86_64-linux-gnu.so.1.2.4"
      "$ENV{DESTDIR}/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib/libshiboken.cpython-35m-x86_64-linux-gnu.so.1.2"
      "$ENV{DESTDIR}/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib/libshiboken.cpython-35m-x86_64-linux-gnu.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib/libshiboken.cpython-35m-x86_64-linux-gnu.so.1.2.4;/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib/libshiboken.cpython-35m-x86_64-linux-gnu.so.1.2;/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib/libshiboken.cpython-35m-x86_64-linux-gnu.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib" TYPE SHARED_LIBRARY FILES
    "/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/shiboken/libshiboken/libshiboken.cpython-35m-x86_64-linux-gnu.so.1.2.4"
    "/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/shiboken/libshiboken/libshiboken.cpython-35m-x86_64-linux-gnu.so.1.2"
    "/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/shiboken/libshiboken/libshiboken.cpython-35m-x86_64-linux-gnu.so"
    )
  foreach(file
      "$ENV{DESTDIR}/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib/libshiboken.cpython-35m-x86_64-linux-gnu.so.1.2.4"
      "$ENV{DESTDIR}/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib/libshiboken.cpython-35m-x86_64-linux-gnu.so.1.2"
      "$ENV{DESTDIR}/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib/libshiboken.cpython-35m-x86_64-linux-gnu.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

