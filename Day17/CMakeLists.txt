add_library(Day17 STATIC
${CMAKE_CURRENT_SOURCE_DIR}/direction.cpp
${CMAKE_CURRENT_SOURCE_DIR}/field.cpp
${CMAKE_CURRENT_SOURCE_DIR}/map.cpp
${CMAKE_CURRENT_SOURCE_DIR}/path.cpp
${CMAKE_CURRENT_SOURCE_DIR}/puzzle.cpp
${CMAKE_CURRENT_SOURCE_DIR}/io.cpp
)

target_include_directories(Day17 PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(Day17 Utils)
