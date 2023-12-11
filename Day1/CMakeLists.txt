add_library(Day1 STATIC
${CMAKE_CURRENT_SOURCE_DIR}/puzzle.cpp 
${CMAKE_CURRENT_SOURCE_DIR}/io.cpp
)

target_include_directories(Day1 PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(Day1 Utils)
