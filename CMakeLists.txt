cmake_minimum_required(VERSION 4.1)
project(dchat)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_RELEASE "-O1 -march=native -Wall -Wextra")

add_executable(dchat
        src/server.cpp
        src/decoder.cpp
        include/decoder.h
        src/usermanager.cpp
        include/usermanager.h
)


