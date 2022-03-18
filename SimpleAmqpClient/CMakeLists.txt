cmake_minimum_required(VERSION 3.22)
project(RabbitMQ VERSION 1.0.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(src)
add_subdirectory(Publisher)
add_subdirectory(Consumer)
add_subdirectory(Executables)





