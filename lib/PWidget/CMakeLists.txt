cmake_minimum_required(VERSION 3.0)

project(PWidget)

message(STATUS "configuring ${PROJECT_NAME}...")

set(CPP_FILES
  )

set(HEADER_FILES
  )

set(QML_FILES
  )

set(QRC_FILES
  )

set(PROJECT_FILES
  ${HEADER_FILES}
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

target_include_directories(${PROJECT_NAME}
  PUBLIC
    ${${PROJECT_NAME}_INCLUDE_DIRS}
  )

target_link_libraries(${PROJECT_NAME}
  PUBLIC
    Qt5::Core
    Qt5::Widgets
    PCore
  )

