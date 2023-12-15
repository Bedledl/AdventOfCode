cmake_minimum_required(VERSION 3.10)

set (CMAKE_CXX_STANDARD 23)
set (CMAKE_CXX_STANDARD_REQUIRED True)

project(AdventOfCode2023)

add_executable(AoC2023 main.cpp)

target_compile_definitions(AoC2023 PRIVATE INPUT_FILES_DIR="${AdventOfCode2023_SOURCE_DIR}/puzzle_input/")

target_include_directories(AoC2023 PUBLIC ${AdventOfCode2023_SOURCE_DIR}/include)

add_subdirectory(Day4)
target_link_libraries(AoC2023 Day4)
add_subdirectory(Day1)
target_link_libraries(AoC2023 Day1)
add_subdirectory(Day2)
target_link_libraries(AoC2023 Day2)

add_subdirectory(utils)
target_link_libraries(AoC2023 Utils)

enable_testing()
add_subdirectory(test)
