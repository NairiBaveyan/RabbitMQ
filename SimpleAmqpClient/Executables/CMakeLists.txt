find_package (Threads)

LINK_DIRECTORIES(/usr/local/Cellar/boost/1.78.0_1/lib)
INCLUDE_DIRECTORIES(/usr/local/Cellar/boost/1.78.0_1/include)

add_executable(main1  test1.cpp)
add_executable(main2  test2.cpp)


set_target_properties(
    main1 PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON)
    set_target_properties(
    main2 PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON)

target_link_libraries(main2 PUBLIC libP)
target_link_libraries(main1 PUBLIC libC)
target_link_libraries(main1 PUBLIC SAMQPC)
target_link_libraries(main2 PUBLIC SAMQPC)
TARGET_LINK_LIBRARIES(main1 LINK_PUBLIC ${boost_cstdint} )
TARGET_LINK_LIBRARIES(main2 LINK_PUBLIC ${boost_cstdint} )#${boost_cstdint}
target_link_libraries(main1 PUBLIC ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(main2 PUBLIC ${CMAKE_THREAD_LIBS_INIT})
  