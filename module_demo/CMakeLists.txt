include_directories("include")


set(DEMO_SOURCES
    main.cpp
)

add_executable(${PROJECT_NAME} ${DEMO_SOURCES})




# add_library(ngspice SHARED IMPORTED)
# set_property(TARGET ngspice PROPERTY IMPORTED_LOCATION "/home/asus/Desktop/cplusplushub/cmakeSizing/lib/libngspice.so")

# add include dirs required for libInterpolate and its dependencies
message(STATUS "PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")

target_link_libraries(${PROJECT_NAME}
    NumCpp::NumCpp
    # ${PROJECT_BINARY_DIR}/lib/libngspice.so
    /home/asus/Desktop/cplusplushub/cmakeSizing/lib/libngspice.so
    # libnsga_library.so
    nsga_library
)
# target_link_libraries(analogsizing libInterpolate::Interpolate )

message(STATUS "========1=========")



# CPAKE is used to do packageing.
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
message(STATUS "========2=========")