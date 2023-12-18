#include <functional>

#include <gtest/gtest.h>

#include "puzzle1.h"
#include "puzzle4.h"
#include "puzzle2.h"

class PuzzleTest : public testing::Test {
    protected:
        std::string name;
        std::function<int()> run_puzzle;
        int expected;

        // not allowed
        //static constexpr std::string test_files_dir = TEST_FILES_DIR;
        static constexpr std::string test_files_dir()  { return TEST_FILES_DIR; };

        std::string build_input_file_name() const {
            return test_files_dir() + "/input" + name  + ".txt"; };

        void init_input(Input &input_obj) {
            input_obj.init_from_file(build_input_file_name());
        }

        void run() {
            int result = run_puzzle();
            EXPECT_EQ(result, expected);
        }
};

TEST_F(PuzzleTest, Puzzle1_1) {
    name = "1_1";
    expected = 142;

    day1::Input1 input(name);
    init_input(input);
    day1::Puzzle1 puzzle{};
    run_puzzle = [&input, &puzzle]() { return puzzle.run_part_1(input); };

    run();
}

TEST_F(PuzzleTest, Puzzle1_2) {
    name = "1_2";
    expected = 281;

    day1::Input1 input(name);
    init_input(input);
    day1::Puzzle1 puzzle{};
    run_puzzle = [&input, &puzzle]() { return puzzle.run_part_2(input); };

    run();
}

TEST_F(PuzzleTest, Puzzle2_1) {
    name = "2_1";
    expected = 8;

    Input2 input(name);
    init_input(input);

    run_puzzle = [&input]() { return run_puzzle_2_1(input); };

    run();
}

TEST_F(PuzzleTest, Puzzle2_2) {
    name = "2_2";
    expected = 2286;

    Input2 input(name);
    init_input(input);

    run_puzzle = [&input]() { return run_puzzle_2_2(input); };

    run();
}

TEST_F(PuzzleTest, Puzzle4) {
    name = "4";
    expected = 13;

    Input4 input(name);
    init_input(input);

    run_puzzle = [&input]() { return run_puzzle_4(input); };

    run();
}
