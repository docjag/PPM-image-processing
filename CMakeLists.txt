cmake_minimum_required(VERSION 3.2)
project(SMTCodingAssessment)

add_subdirectory(${PROJECT_SOURCE_DIR}/src)


add_library(image SHARED image.cpp)
add_library(rgb SHARED rgb.cpp)
add_library(gray SHARED gray.cpp)


add_executable(main main.cpp)

target_link_libraries(main
					  image
					  rgb
					  gray)