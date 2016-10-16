# Install script for directory: /home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/pyside/PySide

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
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib/python3.5/site-packages/PySide/__init__.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib/python3.5/site-packages/PySide" TYPE FILE FILES "/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/__init__.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib/python3.5/site-packages/PySide/_utils.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib/python3.5/site-packages/PySide" TYPE FILE FILES "/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/_utils.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/PySide/typesystems" TYPE FILE FILES "/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/pyside/PySide/typesystem_templates.xml")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/PySide" TYPE FILE FILES "/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/pyside_global.h")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtCore/cmake_install.cmake")
  include("/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtGui/cmake_install.cmake")
  include("/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtNetwork/cmake_install.cmake")
  include("/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtWebKit/cmake_install.cmake")
  include("/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtSvg/cmake_install.cmake")
  include("/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtXml/cmake_install.cmake")
  include("/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtTest/cmake_install.cmake")
  include("/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtOpenGL/cmake_install.cmake")
  include("/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtSql/cmake_install.cmake")
  include("/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtUiTools/cmake_install.cmake")
  include("/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtHelp/cmake_install.cmake")
  include("/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtXmlPatterns/cmake_install.cmake")
  include("/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtScript/cmake_install.cmake")
  include("/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtScriptTools/cmake_install.cmake")
  include("/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/phonon/cmake_install.cmake")
  include("/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtDeclarative/cmake_install.cmake")

endif()

