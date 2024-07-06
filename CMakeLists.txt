cmake_minimum_required(VERSION 3.0.0)
project(analogsizing VERSION 0.1.0 LANGUAGES C CXX)

## Global parameter Begins
SET(LIB_SO_LOCATION "Debug")
## Global parameter Ends

set(CMAKE_BUILD_PARALLEL_LEVEL 4)

# include(CTest)
# enable_testing()
# add the debug mode.
SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -Wextra -Wpedantic \
          -Wformat=2 -Wno-unused-parameter -Wshadow \
          -Wwrite-strings -Wstrict-prototypes -Wold-style-definition \
          -Wredundant-decls -Wnested-externs -Wmissing-include-dirs -g -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

set(LINK_DIR ${PROJECT_SOURCE_DIR}/lib)
 
# Disable setting build tree RPATH on generated executables.
# Set installation destination RPATH as $ORIGIN (that is, the binary directory)
set(CMAKE_SKIP_BUILD_RPATH false)
set(CMAKE_INSTALL_RPATH "${ORIGIN}/lib")


# find libInterpolate
set(CMAKE_INSTALL_PREFIX "/home/asus/Desktop/cplusplushub/dependency")

# set(libInterpolate_DIR "${CMAKE_INSTALL_PREFIX}/lib/cmake/libInterpolate")
# message(STATUS "libInterpolate_DIR: ${libInterpolate_DIR}")
# find_package(libInterpolate REQUIRED)

set(NumCpp_DIR "${CMAKE_INSTALL_PREFIX}/share/NumCpp/cmake")
find_package(NumCpp 2.12.1 REQUIRED)

# create your target

message(STATUS "PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")
message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "CMAKE_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
message(STATUS "EXECUTABLE_OUTPUT_PATH: ${EXECUTABLE_OUTPUT_PATH}")
message(STATUS "LIBRARY_OUTPUT_PATH: ${LIBRARY_OUTPUT_PATH}")
message(STATUS "CMAKE_INCLUDE_PATH: ${CMAKE_INCLUDE_PATH}")
message(STATUS "CMAKE_LIBRARY_PATH: ${CMAKE_LIBRARY_PATH}")

# 设置生成的可执行文件输出目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)


# add_subdirectory(module_nsga "/home/asus/Desktop/cplusplushub/cmakeSizing/build/module_nsga")
add_subdirectory(simulator)
add_subdirectory(module_nsga)
add_subdirectory(module_demo)