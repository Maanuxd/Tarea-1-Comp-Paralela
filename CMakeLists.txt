cmake_minimum_required(VERSION 2.8)
project(ColoreadoImagen)

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( output main.cpp )
target_link_libraries( output ${OpenCV_LIBS} )