add_executable(main test1.cpp test2.cpp)

target_link_libraries(main PRIVATE libP)
target_link_libraries(main PRIVATE libC)
target_link_libraries(main PRIVATE SAMQPC)


