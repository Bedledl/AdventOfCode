
find_package(GTest CONFIG REQUIRED)

# Utils Tests
add_executable(testUtil testUtil.cpp)
target_include_directories(testUtil PUBLIC ${AdventOfCode2023_SOURCE_DIR}/include)

target_link_libraries(testUtil Utils)

target_link_libraries(testUtil GTest::gtest_main)
target_link_libraries(testUtil GTest::gmock_main)
include(GoogleTest)

add_test(
  NAME UtilTest
  COMMAND $<TARGET_FILE:testUtil>
)

target_compile_definitions(testUtil PRIVATE TEST_FILES_DIR="${AdventOfCode2023_SOURCE_DIR}/test/test_input_files/")


# Puzzles Tests
add_test(
    NAME PuzzlesTest
    COMMAND $<TARGET_FILE:testPuzzles>
)

add_executable(testPuzzles testPuzzles.cpp)
target_include_directories(testPuzzles PUBLIC ${AdventOfCode2023_SOURCE_DIR}/include)

target_link_libraries(testPuzzles Day1 Utils)
target_link_libraries(testPuzzles Day2 Utils)
target_link_libraries(testPuzzles Day4 Utils)
target_link_libraries(testPuzzles Day12_bf Utils)
target_link_libraries(testPuzzles Day12 Utils)

target_link_libraries(testPuzzles GTest::gtest_main)
include(GoogleTest)

target_compile_definitions(testPuzzles PRIVATE TEST_FILES_DIR="${AdventOfCode2023_SOURCE_DIR}/test/test_input_files/")
