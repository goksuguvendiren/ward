cmake_minimum_required(VERSION 2.8)
project(ward)

set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS -ljpeg)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Source/main.cpp Source/aoa_jpeg.cpp Source/image.cpp Source/bitmap.cpp)
add_executable(ward ${SOURCE_FILES})