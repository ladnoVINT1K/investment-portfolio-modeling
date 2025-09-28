add_library(backend
    backend.cpp
    backend.hpp
)
target_include_directories(backend PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
