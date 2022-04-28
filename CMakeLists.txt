cmake_minimum_required(VERSION 3.22)
project(Eksamen)

set(CMAKE_CXX_STANDARD 14)

add_executable(Eksamen main.cpp json_parse.cpp json_parse.h rss_reader.cpp rss_reader.h)
