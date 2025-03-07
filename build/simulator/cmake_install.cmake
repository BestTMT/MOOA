# Install script for directory: /home/asus/Desktop/cplusplushub/cmakeSizing/simulator

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/asus/Desktop/cplusplushub/dependency")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/asus/Desktop/cplusplushub/dependency/lib/libsimulator_library.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/asus/Desktop/cplusplushub/dependency/lib/libsimulator_library.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/asus/Desktop/cplusplushub/dependency/lib/libsimulator_library.so"
         RPATH "/lib")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/asus/Desktop/cplusplushub/dependency/lib/libsimulator_library.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/asus/Desktop/cplusplushub/dependency/lib" TYPE SHARED_LIBRARY FILES "/home/asus/Desktop/cplusplushub/cmakeSizing/build/simulator/libsimulator_library.so")
  if(EXISTS "$ENV{DESTDIR}/home/asus/Desktop/cplusplushub/dependency/lib/libsimulator_library.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/asus/Desktop/cplusplushub/dependency/lib/libsimulator_library.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}/home/asus/Desktop/cplusplushub/dependency/lib/libsimulator_library.so"
         OLD_RPATH "/home/asus/Desktop/cplusplushub/cmakeSizing/lib:/home/asus/anaconda3/lib:"
         NEW_RPATH "/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/asus/Desktop/cplusplushub/dependency/lib/libsimulator_library.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/asus/Desktop/cplusplushub/dependency/lib/simulator.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/asus/Desktop/cplusplushub/dependency/lib" TYPE FILE FILES "/home/asus/Desktop/cplusplushub/cmakeSizing/simulator/include/simulator.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/asus/Desktop/cplusplushub/dependency/include/Simulator.h;/home/asus/Desktop/cplusplushub/dependency/include/SimulatorWrapper.h;/home/asus/Desktop/cplusplushub/dependency/include/io_utils.h;/home/asus/Desktop/cplusplushub/dependency/include/sharedspice.h;/home/asus/Desktop/cplusplushub/dependency/include/sharedspice_xspice.h;/home/asus/Desktop/cplusplushub/dependency/include/sim_types.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/asus/Desktop/cplusplushub/dependency/include" TYPE FILE FILES
    "/home/asus/Desktop/cplusplushub/cmakeSizing/simulator/include/Simulator.h"
    "/home/asus/Desktop/cplusplushub/cmakeSizing/simulator/include/SimulatorWrapper.h"
    "/home/asus/Desktop/cplusplushub/cmakeSizing/simulator/include/io_utils.h"
    "/home/asus/Desktop/cplusplushub/cmakeSizing/simulator/include/sharedspice.h"
    "/home/asus/Desktop/cplusplushub/cmakeSizing/simulator/include/sharedspice_xspice.h"
    "/home/asus/Desktop/cplusplushub/cmakeSizing/simulator/include/sim_types.h"
    )
endif()

