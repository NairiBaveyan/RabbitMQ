LINK_DIRECTORIES(/usr/local/Cellar/boost/1.78.0_1/lib)
INCLUDE_DIRECTORIES(/usr/local/Cellar/boost/1.78.0_1/include)



add_library(libP  #static
    MyPublisher.hpp
    MyPublisher.cpp
)

set_target_properties(
   libP PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON)


TARGET_LINK_LIBRARIES( libP LINK_PUBLIC ${boost_cstdint} )
target_include_directories(libP PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Publisher")


