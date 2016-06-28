cmake_minimum_required(VERSION 3.0)

project(PViewer)

message(STATUS "configuring ${PROJECT_NAME}...")

set(CPP_FILES
  main.cpp
  PMainWindow.cpp
  )

set(HEADER_FILES
  PMainWindow.h
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
  PCore
  PWidget
  PVtkView
  )
