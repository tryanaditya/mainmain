# Install script for directory: /home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/pyside/PySide/QtScriptTools

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
  if(EXISTS "$ENV{DESTDIR}/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib/python3.5/site-packages/PySide/QtScriptTools.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib/python3.5/site-packages/PySide/QtScriptTools.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib/python3.5/site-packages/PySide/QtScriptTools.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib/python3.5/site-packages/PySide/QtScriptTools.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib/python3.5/site-packages/PySide" TYPE MODULE FILES "/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtScriptTools.so")
  if(EXISTS "$ENV{DESTDIR}/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib/python3.5/site-packages/PySide/QtScriptTools.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib/python3.5/site-packages/PySide/QtScriptTools.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib/python3.5/site-packages/PySide/QtScriptTools.so"
         OLD_RPATH "/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/libpyside:/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib/python3.5/site-packages/PySide/QtScriptTools.so")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/PySide/QtScriptTools" TYPE FILE FILES "/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside/PySide/QtScriptTools/PySide/QtScriptTools/pyside_qtscripttools_python.h")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/PySide/typesystems" TYPE FILE FILES
    "/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/pyside/PySide/QtScriptTools/typesystem_scripttools.xml"
    "/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/pyside/PySide/QtScriptTools/typesystem_scripttools.xml"
    )
endif()

