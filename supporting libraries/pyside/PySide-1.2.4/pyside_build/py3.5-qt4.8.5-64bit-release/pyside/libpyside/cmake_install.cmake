# Install script for directory: /root/pyside/PySide-1.2.4/sources/pyside/libpyside

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
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/PySide" TYPE FILE FILES
    "/root/pyside/PySide-1.2.4/sources/pyside/libpyside/destroylistener.h"
    "/root/pyside/PySide-1.2.4/sources/pyside/libpyside/dynamicqmetaobject.h"
    "/root/pyside/PySide-1.2.4/sources/pyside/libpyside/globalreceiver.h"
    "/root/pyside/PySide-1.2.4/sources/pyside/libpyside/pysideclassinfo.h"
    "/root/pyside/PySide-1.2.4/sources/pyside/libpyside/pysideconversions.h"
    "/root/pyside/PySide-1.2.4/sources/pyside/libpyside/pysidemacros.h"
    "/root/pyside/PySide-1.2.4/sources/pyside/libpyside/signalmanager.h"
    "/root/pyside/PySide-1.2.4/sources/pyside/libpyside/pyside.h"
    "/root/pyside/PySide-1.2.4/sources/pyside/libpyside/pysidemetafunction.h"
    "/root/pyside/PySide-1.2.4/sources/pyside/libpyside/pysidesignal.h"
    "/root/pyside/PySide-1.2.4/sources/pyside/libpyside/pysideproperty.h"
    "/root/pyside/PySide-1.2.4/sources/pyside/libpyside/pysideqflags.h"
    "/root/pyside/PySide-1.2.4/sources/pyside/libpyside/pysideweakref.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FOREACH(file
      "$ENV{DESTDIR}/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/libpyside.cpython-35m-x86_64-linux-gnu.so.1.2.4"
      "$ENV{DESTDIR}/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/libpyside.cpython-35m-x86_64-linux-gnu.so.1.2"
      "$ENV{DESTDIR}/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/libpyside.cpython-35m-x86_64-linux-gnu.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      FILE(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    ENDIF()
  ENDFOREACH()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/libpyside.cpython-35m-x86_64-linux-gnu.so.1.2.4;/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/libpyside.cpython-35m-x86_64-linux-gnu.so.1.2;/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/libpyside.cpython-35m-x86_64-linux-gnu.so")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib" TYPE SHARED_LIBRARY FILES
    "/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside/libpyside/libpyside.cpython-35m-x86_64-linux-gnu.so.1.2.4"
    "/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside/libpyside/libpyside.cpython-35m-x86_64-linux-gnu.so.1.2"
    "/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside/libpyside/libpyside.cpython-35m-x86_64-linux-gnu.so"
    )
  FOREACH(file
      "$ENV{DESTDIR}/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/libpyside.cpython-35m-x86_64-linux-gnu.so.1.2.4"
      "$ENV{DESTDIR}/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/libpyside.cpython-35m-x86_64-linux-gnu.so.1.2"
      "$ENV{DESTDIR}/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/libpyside.cpython-35m-x86_64-linux-gnu.so"
      )
    IF(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      FILE(RPATH_REMOVE
           FILE "${file}")
      IF(CMAKE_INSTALL_DO_STRIP)
        EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "${file}")
      ENDIF(CMAKE_INSTALL_DO_STRIP)
    ENDIF()
  ENDFOREACH()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/pkgconfig/pyside.pc")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/pkgconfig" TYPE FILE FILES "/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside/libpyside/pyside.pc")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/cmake/PySide-1.2.4/PySideConfig.cmake")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/cmake/PySide-1.2.4" TYPE FILE FILES "/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside/libpyside/PySideConfig.cmake")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/cmake/PySide-1.2.4/PySideConfig.cpython-35m-x86_64-linux-gnu.cmake")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/cmake/PySide-1.2.4" TYPE FILE FILES "/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside/libpyside/PySideConfig.cpython-35m-x86_64-linux-gnu.cmake")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/cmake/PySide-1.2.4/PySideConfigVersion.cmake")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/cmake/PySide-1.2.4" TYPE FILE FILES "/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside/libpyside/PySideConfigVersion.cmake")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

