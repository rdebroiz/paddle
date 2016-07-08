cmake_minimum_required(VERSION 3.0)

project(PWidgets)

message(STATUS "configuring ${PROJECT_NAME}...")

find_package(Qt5 REQUIRED COMPONENTS
  Gui
  Widgets
  )

set(CPP_FILES
  parameter/PAbstractParameterPresenter.cpp
  parameter/PBoolPresenter.cpp
  parameter/PIntPresenter.cpp
  parameter/PDoublePresenter.cpp
  )

set(HEADER_FILES
  parameter/PAbstractParameterPresenter.h
  parameter/PBoolPresenter.h
  parameter/PIntPresenter.h
  parameter/PDoublePresenter.h
  )

set(HEADER_FILES_PRIVATE
  parameter/private/PAbstractParameterPresenter_p.h
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
    PCore
    Qt5::Gui
    Qt5::Widgets
  )
