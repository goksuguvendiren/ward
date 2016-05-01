cmake_minimum_required(VERSION 2.8)
project(ward)

find_package(OpenCV REQUIRED)

set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS -ljpeg)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -std=c++11")

set(SOURCE_FILES Source/main.cpp Source/aoa_jpeg.cpp Source/image.cpp Source/bitmap.cpp Source/ward.cpp)
add_executable(ward ${SOURCE_FILES})

target_link_libraries(ward ${OpenCV_LIBS})