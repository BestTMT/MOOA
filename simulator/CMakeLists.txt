#Speicial for local debug Begins

# cmake_minimum_required(VERSION 3.0.0)
# project(nsga VERSION 0.1.0 LANGUAGES C CXX) 

#special for local debug Ends

# set(SRC_LIST simulator.cpp )

file(GLOB SRC_LIST "*.cpp")
message(STATUS "SRC_LIST: ${SRC_LIST}")


message(STATUS "CMAKE_CURRENT_SOURCE_DIR/include: ${CMAKE_CURRENT_SOURCE_DIR}/include/")
file(GLOB SRCS_INCLUDE  ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
message(STATUS "SRCS_INCLUDE: ${SRCS_INCLUDE}")



set(SIMULATOR_VERSION 1)

add_library(simulator_library SHARED ${SRC_LIST})
# install(TARGETS nsga_library DESTINATION .)


target_link_libraries(simulator_library
    NumCpp::NumCpp
    # ${PROJECT_BINARY_DIR}/lib/libngspice.so
    /home/asus/Desktop/cplusplushub/cmakeSizing/lib/libngspice.so
)

set_target_properties(simulator_library PROPERTIES 
	OUTPUT_NAME "simulator_library"
	PUBLIC_HEADER "include/simulator.h"
)
# set_target_properties(nsga_library PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# message(STATUS "CMAKE_INSTALL_PREFIX Location: ${CMAKE_INSTALL_PREFIX}")



# 安装
install(TARGETS simulator_library DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install(FILES ${SRCS_INCLUDE} DESTINATION ${CMAKE_INSTALL_PREFIX}/include)