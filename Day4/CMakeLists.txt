add_library(Day4 STATIC
${CMAKE_CURRENT_SOURCE_DIR}/pileProcessor.cpp
${CMAKE_CURRENT_SOURCE_DIR}/puzzle.cpp
${CMAKE_CURRENT_SOURCE_DIR}/io.cpp
)

target_include_directories(Day4 PUBLIC
${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(Day4 Utils)
