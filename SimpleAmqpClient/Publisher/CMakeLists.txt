
add_library(libP SHARED
    MyPublisher.hpp
    MyPublisher.cpp
)

target_include_directories(libP PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Publisher")

set_target_properties(
    libP PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)

