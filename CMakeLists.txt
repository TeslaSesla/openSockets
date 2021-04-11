cmake_minimum_required(VERSION 3.5)

project(openSockets LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(openSockets main.cpp server.cpp server.h client.cpp client.h)
