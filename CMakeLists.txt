cmake_minimum_required(VERSION 3.30)
project(particleeffect)

set(CMAKE_CXX_STANDARD 20)

find_package(glfw3 REQUIRED)
include_directories(${CMAKE_SOURCE_DIR}/include)
set(GLAD_SOURCES ${CMAKE_SOURCE_DIR}/src/glad.c)

add_executable(particleeffect src/main.cpp ${GLAD_SOURCES})
target_link_libraries(particleeffect glfw)
