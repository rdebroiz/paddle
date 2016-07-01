cmake_minimum_required(VERSION 3.0)

project(PCoreTest)

message(STATUS "configuring ${PROJECT_NAME}...")

set(CPP_FILES
  parameter/PAbstractParameterTest.cpp
  parameter/PBoolParameterTest.cpp
  parameter/PBoolGroupTest.cpp
  parameter/PIntParameterTest.cpp
  )

foreach(test_file ${CPP_FILES})
  get_filename_component(test_name ${test_file} NAME_WE)
  add_executable(${test_name} ${test_file})
  target_link_libraries(${test_name}
    PUBLIC
      PCore
      Qt5::Test
    )
   add_test(${test_name} ${test_name})
endforeach()
