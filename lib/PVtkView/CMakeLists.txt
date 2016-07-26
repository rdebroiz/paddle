cmake_minimum_required(VERSION 3.0)

project(PVtkView)

message(STATUS "configuring ${PROJECT_NAME}...")

find_package(Qt5 REQUIRED COMPONENTS
  OpenGL
  )

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

set(CPP_FILES
  PVtkGraphicsView.cpp
  PVtkGraphicsItem.cpp
  PVtkInteractorAdapter.cpp
  PVtkView.cpp
  )

set(HEADER_FILES
  PVtkGraphicsView.h
  PVtkGraphicsItem.h
  PVtkInteractorAdapter.h
  PVtkView.h
  )

set(HEADER_FILES_PRIVATE
  )

set(QML_FILES
  )

set(QRC_FILES
  )

set(PROJECT_FILES
  ${HEADER_FILES}
  ${HEADER_FILES_PRIVATE}
  ${CPP_FILES}
  ${QML_FILES}
  ${QRC_FILES}
  )

add_library(${PROJECT_NAME} SHARED
  ${PROJECT_FILES}
  )

foreach(headers_path ${HEADER_FILES})
  get_filename_component(dir_path ${CMAKE_CURRENT_SOURCE_DIR}/${headers_path} DIRECTORY)
  set(${PROJECT_NAME}_INCLUDE_DIRS
    ${dir_path}
    ${${PROJECT_NAME}_INCLUDE_DIRS}
    )
endforeach()


if(DEFINED ${PROJECT_NAME}_INCLUDE_DIRS)
  list(REMOVE_DUPLICATES ${PROJECT_NAME}_INCLUDE_DIRS)
endif()

foreach(headers_path_private ${HEADER_FILES_PRIVATE})
  get_filename_component(dir_path_private ${CMAKE_CURRENT_SOURCE_DIR}/${headers_path_private} DIRECTORY)
  set(${PROJECT_NAME}_INCLUDE_DIRS_PRIVATE
    ${dir_path_private}
    ${${PROJECT_NAME}_INCLUDE_DIRS_PRIVATE}
    )
endforeach()


if(DEFINED ${PROJECT_NAME}_INCLUDE_DIRS_PRIVATE)
  list(REMOVE_DUPLICATES ${PROJECT_NAME}_INCLUDE_DIRS_PRIVATE)
endif()

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${${PROJECT_NAME}_INCLUDE_DIRS}
  PRIVATE
    ${${PROJECT_NAME}_INCLUDE_DIRS_PRIVATE}
  )

target_link_libraries(${PROJECT_NAME}
  PUBLIC
    PWidgets
    Qt5::OpenGL
    ${VTK_LIBRARIES}
  )
