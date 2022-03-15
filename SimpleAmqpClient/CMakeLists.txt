cmake_minimum_required(VERSION 3.12)
project(RabbitMQ VERSION 1.0.0)



add_subdirectory(src)
add_subdirectory(Executables)
add_subdirectory(Publisher)
add_subdirectory(Consumer)


#add_executable(rmqProject test.cpp test2.cpp) 
#add_executable(cmakeGood main.cpp Nairi.cpp) or add_library()


