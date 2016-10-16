# Install script for directory: /home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/pyside-tools

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE FILE PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_READ WORLD_EXECUTE WORLD_READ FILES "/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/pyside-tools/pyside-uic")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib/python3.5/site-packages/pysideuic/__init__.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib/python3.5/site-packages/pysideuic" TYPE FILE FILES "/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside-tools/__init__.py")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib/python3.5/site-packages/pysideuic")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.7-64bit-release/lib/python3.5/site-packages" TYPE DIRECTORY FILES "/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/pyside-tools/pysideuic" REGEX "/[^/]*\\.in$" EXCLUDE REGEX "/[^/]*pysideuic\\/\\_\\_init\\_\\_\\.py$" EXCLUDE REGEX "/[^/]*pysideuic\\\\\\_\\_init\\_\\_\\.py$" EXCLUDE)
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/man/man1" TYPE FILE FILES "/home/tryan/voice_analytics/pyside/PySide-1.2.4/sources/pyside-tools/pysideuic/pyside-uic.1")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside-tools/pyrcc/cmake_install.cmake")
  include("/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside-tools/pylupdate/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/tryan/voice_analytics/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.7-64bit-release/pyside-tools/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
