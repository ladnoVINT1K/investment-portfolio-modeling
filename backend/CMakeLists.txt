add_library(backend
    investments.hpp
    market.hpp
)
target_include_directories(backend PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
