project(training-cpp-concurrency)

cmake_minimum_required(VERSION 2.8)

include(${PROJECT_SOURCE_DIR}/CMake/utils.cmake)

# for gcc
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic")

add_subdirectory("MyFramework")
add_subdirectory("MyApps")



