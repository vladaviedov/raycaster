cmake_minimum_required(VERSION 3.0)

set(PROJ_NAME rc)
project(${PROJ_NAME} VERSION 0.1)
set(CMAKE_C_FLAGS "-Wall -Wextra" CACHE STRING "" FORCE)

cmake_policy(SET CMP0072 NEW)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

file (GLOB SOURCES src/*.c)
add_executable(${PROJ_NAME} ${SOURCES})
target_link_libraries(${PROJ_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})
