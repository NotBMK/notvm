cmake_minimum_required(VERSION 3.22)

project(notvm)

include_directories(include)

set(SOURCE_DIR "./source")

file(GLOB_RECURSE SOURCES "${SOURCE_DIR}/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})