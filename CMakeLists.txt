cmake_minimum_required(VERSION 3.5)
project(8051Emu)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Processor.cpp Processor.h HexParser.cpp HexParser.h ops.cpp ops.h Memory.cpp Memory.h Sfr.cpp Sfr.h sfrs.cpp sfrs.h)
add_executable(8051Emu ${SOURCE_FILES})