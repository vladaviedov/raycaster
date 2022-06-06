cmake_minimum_required(VERSION 3.0)

set(PROJ_NAME rc)
project(${PROJ_NAME} VERSION 0.1)
set(CMAKE_C_FLAGS "-Wall -Wextra" CACHE STRING "" FORCE)

file (GLOB SOURCES src/*.c)
add_executable(${PROJ_NAME} ${SOURCES})
