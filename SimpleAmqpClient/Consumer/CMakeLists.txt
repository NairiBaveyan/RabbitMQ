LINK_DIRECTORIES(/usr/local/Cellar/boost/1.78.0_1/lib)
INCLUDE_DIRECTORIES(/usr/local/Cellar/boost/1.78.0_1/include)



add_library(libC 
            myConsumer.hpp
            myConsumer.cpp
)

TARGET_LINK_LIBRARIES( libC LINK_PUBLIC ${boost_cstdint} )

target_include_directories(libC PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Consumer")

