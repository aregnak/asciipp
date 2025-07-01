cmake_minimum_required(VERSION 3.5)
project(asciipp)

find_package(OpenCV REQUIRED)

add_executable(asciipp src/main.cpp)
target_link_libraries(asciipp ${OpenCV_LIBS})
