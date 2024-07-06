#Speicial for local debug Begins

# cmake_minimum_required(VERSION 3.0.0)
# project(nsga VERSION 0.1.0 LANGUAGES C CXX) 

#special for local debug Ends

set(SRC_LIST allocate.c auxiliary.c crossover.c decode.c display.c dominance.c eval.c fillnds.c initialize.c list.c merge.c metrics.c mutation.c nsga2r.c problemdef.c rand.c rank.c referencepoints.c report.c selection.c sort.c tourselect.c)

message(STATUS "CMAKE_CURRENT_SOURCE_DIR/include: ${CMAKE_CURRENT_SOURCE_DIR}/include/")
file(GLOB SRCS_INCLUDE  ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)
message(STATUS "SRCS_INCLUDE: ${SRCS_INCLUDE}")


# IF(IS_DEBUG STREQUAL "TRUE")

#     message(STATUS "==============2=====================")
#     set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/build/bin)


#     SET(IS_DEBUG "====1====================")

#     message(STATUS "IS_DEBUG: ${IS_DEBUG}")

#     # add the debug mode.
#     SET(CMAKE_BUILD_TYPE "Debug")
#     # set(CMAKE_CXX_STANDARD 17)
#     SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
#     SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

#     include_directories("/home/asus/Desktop/cplusplushub/cmakeSizing/module_nsga/")

#     add_executable(nsga ${SRC_LIST})
#     target_link_libraries(nsga m)

#     message(STATUS "PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")

#     # CPAKE is used to do packageing.
#     set(CPACK_PROJECT_NAME ${PROJECT_NAME})
#     set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
#     include(CPack)


#     ELSE()
#         message(STATUS "==============2=====================")

# endif(IS_DEBUG)


set(NSGA_VERSION 1)

add_library(nsga_library SHARED ${SRC_LIST})
# install(TARGETS nsga_library DESTINATION .)

set_target_properties(nsga_library PROPERTIES 
	OUTPUT_NAME "nsga_library"
	PUBLIC_HEADER "include/nsga2r.h"
)
# set_target_properties(nsga_library PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# message(STATUS "CMAKE_INSTALL_PREFIX Location: ${CMAKE_INSTALL_PREFIX}")


install(DIRECTORY "/home/asus/Desktop/cplusplushub/cmakeSizing/module_nsga/real_front" DESTINATION ${PROJECT_BINARY_DIR}/bin)

# 安装
install(TARGETS nsga_library DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install(FILES ${SRCS_INCLUDE} DESTINATION ${CMAKE_INSTALL_PREFIX}/include)

message(STATUS "CMAKE_INSTALL_PREFIX lib Location: ${CMAKE_INSTALL_PREFIX}/lib")


target_link_libraries(nsga_library simulator_library)


# Export the library's public include path to dependent targets
# target_include_directories(nsga_library
# 	INTERFACE
#     	${PROJECT_BINARY_DIR}
# )


# Treat the exported symbols as exported (and not imported) when building the library
# target_compile_definitions(nsga_library
# 	PRIVATE
# 		NSGA_LIBRARY_BUILD
# )


# Add "library_support" to include path. This has to be public because it's used in library's public headers.
# target_link_libraries(nsga_library
# 	PUBLIC
# 		library_support
# )

