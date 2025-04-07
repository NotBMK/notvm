cmake_minimum_required(VERSION 3.22)

project(notvm)

include_directories(include)

set(SOURCE_DIR "./source")

file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/*.cpp")

add_library(${PROJECT_NAME} STATIC ${SOURCES})

add_subdirectory(testVM)