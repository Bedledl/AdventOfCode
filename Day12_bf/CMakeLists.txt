add_library(Day12_bf STATIC
${CMAKE_CURRENT_SOURCE_DIR}/puzzle.cpp
${CMAKE_CURRENT_SOURCE_DIR}/io.cpp
)

target_include_directories(Day12_bf PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(Day12_bf Utils)
