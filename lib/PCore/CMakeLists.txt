cmake_minimum_required(VERSION 3.0)

project(PCore)

message(STATUS "configuring ${PROJECT_NAME}...")

set(CPP_FILES
  parameter/PAbstractParameter.cpp
  parameter/PBoolParameter.cpp
  parameter/PBoolGroup.cpp
  parameter/PIntParameter.cpp
  )

set(HEADER_FILES
  parameter/PAbstractParameter.h
  parameter/PBoolParameter.h
  parameter/PBoolGroup.h
  parameter/PIntParameter.h
  )

set(HEADER_FILES_PRIVATE
  parameter/private/PAbstractParameter_p.h
  parameter/private/PBoolParameter_p.h
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
    Qt5::Core
  )


if(PADDLE_BUILD_TESTS)
    add_subdirectory(tests)
endif()
