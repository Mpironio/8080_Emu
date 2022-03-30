cmake_minimum_required(VERSION 3.20)

project(8080Emu)

file(GLOB SOURCE_FILES src/*.cpp src/*.h src/*.hpp)

add_executable(8080emu ${SOURCE_FILES})