cmake_minimum_required(VERSION 3.17)
project(cpp_lab)

file(GLOB SOURCES
        *.h
        *.cpp
        *.in.txt
        )

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_lab ejercicio1.cpp ${SOURCE_FILES} ${SOURCES} ejercicio2.cpp tads/hash.h tads/hash.cpp)