cmake_minimum_required(VERSION 3.5)
project(Asciipp)

find_package(OpenCV REQUIRED)

add_executable(Asciipp main.cpp)
target_link_libraries(AsciiArt ${OpenCV_LIBS})
