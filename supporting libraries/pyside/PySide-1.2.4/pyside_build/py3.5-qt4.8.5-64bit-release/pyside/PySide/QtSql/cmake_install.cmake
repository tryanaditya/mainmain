# Install script for directory: /root/pyside/PySide-1.2.4/sources/pyside/PySide/QtSql

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
  IF(EXISTS "$ENV{DESTDIR}/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/python3.5/site-packages/PySide/QtSql.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/python3.5/site-packages/PySide/QtSql.so")
    FILE(RPATH_CHECK
         FILE "$ENV{DESTDIR}/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/python3.5/site-packages/PySide/QtSql.so"
         RPATH "")
  ENDIF()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/python3.5/site-packages/PySide/QtSql.so")
  IF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
  IF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  ENDIF (CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
FILE(INSTALL DESTINATION "/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/python3.5/site-packages/PySide" TYPE MODULE FILES "/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside/PySide/QtSql.so")
  IF(EXISTS "$ENV{DESTDIR}/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/python3.5/site-packages/PySide/QtSql.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/python3.5/site-packages/PySide/QtSql.so")
    FILE(RPATH_REMOVE
         FILE "$ENV{DESTDIR}/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/python3.5/site-packages/PySide/QtSql.so")
    IF(CMAKE_INSTALL_DO_STRIP)
      EXECUTE_PROCESS(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/root/pyside/PySide-1.2.4/pyside_install/py3.5-qt4.8.5-64bit-release/lib/python3.5/site-packages/PySide/QtSql.so")
    ENDIF(CMAKE_INSTALL_DO_STRIP)
  ENDIF()
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/PySide/QtSql" TYPE FILE FILES "/root/pyside/PySide-1.2.4/pyside_build/py3.5-qt4.8.5-64bit-release/pyside/PySide/QtSql/PySide/QtSql/pyside_qtsql_python.h")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/PySide/typesystems" TYPE FILE FILES
    "/root/pyside/PySide-1.2.4/sources/pyside/PySide/QtSql/typesystem_sql.xml"
    "/root/pyside/PySide-1.2.4/sources/pyside/PySide/QtSql/typesystem_sql.xml"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")

