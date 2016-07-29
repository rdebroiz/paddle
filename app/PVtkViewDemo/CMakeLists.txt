cmake_minimum_required(VERSION 3.0)

project(PVtkViewDemo)

message(STATUS "configuring ${PROJECT_NAME}...")

find_package(ITK REQUIRED)
include(${ITK_USE_FILE})

set(CPP_FILES
  main.cpp
  MainWindow.cpp
  )

set(HEADER_FILES
  MainWindow.h
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

add_executable(${PROJECT_NAME}
  ${PROJECT_FILES}
  )

target_link_libraries(${PROJECT_NAME}
  PVtkView
  ${ITK_LIBRARIES}
  )

