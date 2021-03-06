# Install script for directory: /root/pyside/PySide-1.2.4/sources/pyside/PySide

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
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/python3.5/site-packages/PySide/__init__.py")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/python3.5/site-packages/PySide" TYPE FILE FILES "/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside/PySide/__init__.py")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/python3.5/site-packages/PySide/_utils.py")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/python3.5/site-packages/PySide" TYPE FILE FILES "/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside/PySide/_utils.py")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/PySide/typesystems" TYPE FILE FILES "/root/pyside/PySide-1.2.4/sources/pyside/PySide/typesystem_templates.xml")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/PySide" TYPE FILE FILES "/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside/PySide/pyside_global.h")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  INCLUDE("/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside/PySide/QtCore/cmake_install.cmake")
  INCLUDE("/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside/PySide/QtGui/cmake_install.cmake")
  INCLUDE("/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside/PySide/QtNetwork/cmake_install.cmake")
  INCLUDE("/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside/PySide/QtSvg/cmake_install.cmake")
  INCLUDE("/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside/PySide/QtXml/cmake_install.cmake")
  INCLUDE("/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside/PySide/QtTest/cmake_install.cmake")
  INCLUDE("/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside/PySide/QtOpenGL/cmake_install.cmake")
  INCLUDE("/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside/PySide/QtSql/cmake_install.cmake")
  INCLUDE("/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside/PySide/QtUiTools/cmake_install.cmake")
  INCLUDE("/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside/PySide/QtHelp/cmake_install.cmake")
  INCLUDE("/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside/PySide/QtXmlPatterns/cmake_install.cmake")
  INCLUDE("/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside/PySide/QtScript/cmake_install.cmake")
  INCLUDE("/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside/PySide/QtScriptTools/cmake_install.cmake")
  INCLUDE("/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside/PySide/QtMultimedia/cmake_install.cmake")
  INCLUDE("/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside/PySide/QtDeclarative/cmake_install.cmake")

ENDIF(NOT CMAKE_INSTALL_LOCAL_ONLY)

