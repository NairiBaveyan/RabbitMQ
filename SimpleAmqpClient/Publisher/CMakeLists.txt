LINK_DIRECTORIES(/usr/local/Cellar/boost/1.78.0_1/lib)
INCLUDE_DIRECTORIES(/usr/local/Cellar/boost/1.78.0_1/include)



ADD_LIBRARY(libP  #static
    MyPublisher.hpp
    MyPublisher.cpp
)
SET_TARGET_PROPERTIES(
   libP PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON)


TARGET_LINK_LIBRARIES( libP LINK_PUBLIC ${boost_cstdint} )
TARGET_INCLUDE_DIRECTORIES(libP PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Publisher")


