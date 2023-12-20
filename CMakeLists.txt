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
add_subdirectory(Day12_bf)
target_link_libraries(AoC2023 Day12_bf)

add_subdirectory(utils)
target_link_libraries(AoC2023 Utils)

enable_testing()
add_subdirectory(test)


if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    # require at least gcc 4.8
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 12)
        message(FATAL_ERROR "GCC version must be at least 12! Currently: ${CMAKE_CXX_COMPILER_VERSION}")
    endif()
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    # require at least clang 3.2
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 16)
        message(FATAL_ERROR "Clang version must be at least 16! Currently: ${CMAKE_CXX_COMPILER_VERSION}")
    endif()
else()
    message(WARNING "You are using an unsupported compiler! Compilation has only been tested with Clang and GCC.")
endif()
