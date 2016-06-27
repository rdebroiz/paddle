cmake_minimum_required(VERSION 3.0)

project(paddle)

find_package(Qt5 REQUIRED COMPONENTS
  Core
  Gui
  Widgets
  Quick
  )

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
#   Find includes in corresponding build (and source) directories
#   (nedded for generated files)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

add_subdirectory(app)
add_subdirectory(lib)
