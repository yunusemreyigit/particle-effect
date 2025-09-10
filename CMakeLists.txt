cmake_minimum_required(VERSION 3.30)
project(particleeffect)

set(CMAKE_CXX_STANDARD 20)

find_package(glfw3 REQUIRED)
include_directories(${CMAKE_SOURCE_DIR}/include)
set(GLAD_SOURCES ${CMAKE_SOURCE_DIR}/src/glad.c)
file (GLOB SOURCES
        "src/Viewer/*.cpp"
        "src/Controller/*.cpp"
    "src/*.cpp"
    "src/[!main]*.cpp"
)
add_executable(particleeffect src/main.cpp ${GLAD_SOURCES} ${SOURCES})
target_link_libraries(particleeffect glfw)
