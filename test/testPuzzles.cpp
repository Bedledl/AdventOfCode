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


        std::string build_input_file_name() const {
            return std::string(TEST_FILES_DIR) + "/input" + name  + ".txt"; };

        void init_input(Input &input_obj) {
            input_obj.init_from_file(build_input_file_name());
        }

        void run() {
            int result = run_puzzle();
            EXPECT_EQ(result, expected);
        }
};

TEST_F(PuzzleTest, Puzzle1) {
    name = "1";
    expected = 142;

    Input1 input(name);
    init_input(input);

    run_puzzle = [&input]() { return run_puzzle_1(input); };

    run();
}

TEST_F(PuzzleTest, Puzzle2) {
    name = "2";
    expected = 8;

    Input2 input(name);
    init_input(input);

    run_puzzle = [&input]() { return run_puzzle_2(input); };

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
