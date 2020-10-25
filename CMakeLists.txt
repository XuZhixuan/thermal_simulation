cmake_minimum_required(VERSION 3.0.0)
project(thermal_simulation VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(
    include
)

aux_source_directory(src SRC_DIR)

add_executable(simulation ${SRC_DIR})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
