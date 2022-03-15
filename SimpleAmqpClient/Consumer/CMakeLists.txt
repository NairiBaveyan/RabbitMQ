cmake_minimum_required(VERSION 3.12)
project(ConsLib)

add_library(libC
            myConsumer.hpp
            myConsumer.cpp
)


target_include_directories(libC PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Consumer")

set_target_properties(
    libC PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)