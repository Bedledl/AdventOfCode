add_library(Day2 STATIC
${CMAKE_CURRENT_SOURCE_DIR}/puzzle.cpp 
${CMAKE_CURRENT_SOURCE_DIR}/io.cpp
)

target_include_directories(Day2 PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(Day2 Utils)
