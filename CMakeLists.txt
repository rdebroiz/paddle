cmake_minimum_required(VERSION 3.0)

project(PADDLE)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
#   Find includes in corresponding build (and source) directories
#   (nedded for generated files)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#find_package(ITK REQUIRED)
#include(${ITK_USE_FILE})

option(${PROJECT_NAME}_BUILD_TESTS "Build tests for ${PROJECT_NAME}" ON)
if(${PROJECT_NAME}_BUILD_TESTS)
    enable_testing()
    message(STATUS "Tests have been enabled.")
endif()

add_subdirectory(app)
add_subdirectory(lib)
