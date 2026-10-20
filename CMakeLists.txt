cmake_minimum_required(VERSION 3.15)
project(rayTracer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMALE_BUILD_TYPE)
    set(CMALE_BUILD_TYPE Release)
endif()

add_executable(firstImage src/creatingFirstImage.cpp)
add_executable(secondImage src/creatingSecondImage.cpp)
