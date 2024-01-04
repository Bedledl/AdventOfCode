#include <functional>

#include <gtest/gtest.h>

#include "puzzle1.h"
#include "puzzle4.h"
#include "puzzle2.h"
#include "puzzle12_bf.h"
#include "puzzle12.h"
#include "puzzle17.h"

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

    day2::Input2 input(name);
    init_input(input);

    day2::Puzzle2 puzzle{};

    run_puzzle = [&input, &puzzle]() { return puzzle.run_part_1(input); };

    run();
}

TEST_F(PuzzleTest, Puzzle2_2) {
    name = "2_2";
    expected = 2286;

    day2::Input2 input(name);
    init_input(input);

    day2::Puzzle2 puzzle;

    run_puzzle = [&input, &puzzle]() { return puzzle.run_part_2(input); };

    run();
}

TEST_F(PuzzleTest, Puzzle4_1) {
    name = "4";
    expected = 13;

    day4::Input4 input(name);
    init_input(input);

    day4::Puzzle4 puzzle;

    run_puzzle = [&input, &puzzle]() { return puzzle.run_part_1(input); };

    run();
}

TEST_F(PuzzleTest, Puzzle4_2) {
    name = "4";
    expected = 30;

    day4::Input4 input(name);
    init_input(input);

    day4::Puzzle4 puzzle;

    run_puzzle = [&input, &puzzle]() { return puzzle.run_part_2(input); };

    run();
}

TEST_F(PuzzleTest, Puzzle12_1) {
    name = "12_1_bf";
    expected = 21;

    day12_bf::Input12 input(name);
    init_input(input);

    day12_bf::Puzzle12 puzzle{};

    run_puzzle = [&input, &puzzle]() { return puzzle.run_part_1(input); };

    run();
}

// TEST_F(PuzzleTest, Puzzle12_2) {
//     name = "12_2_bf";
//     expected = 16;

//     day12_bf::Input12 input(name);
//     init_input(input);

//     day12_bf::Puzzle12 puzzle{};

//     run_puzzle = [&input, &puzzle]() { return puzzle.run_part_2(input); };

//     run();
// }

// TEST_F(PuzzleTest, Puzzle12_1_optim) {
//     name = "12_1_optim";
//     expected = 21;

//     day12::Input12 input(name);
//     init_input(input);

//     day12::Puzzle12 puzzle{};

//     run_puzzle = [&input, &puzzle]() { return puzzle.run_part_1(input); };

//     run();
// }

// TEST_F(PuzzleTest, Puzzle12_2_optim) {
//     name = "12_2_optim";
//     expected = 525152;

//     day12::Input12 input(name);
//     init_input(input);

//     day12::Puzzle12 puzzle{};

//     run_puzzle = [&input, &puzzle]() { return puzzle.run_part_2(input); };

//     run();
// }


TEST_F(PuzzleTest, Puzzle17_1) {
    name = "17_1";
    expected = 791;

    day17::Input17 input(name, 3);
    init_input(input);

    day17::Puzzle17 puzzle{};

    run_puzzle = [&input, &puzzle]() { return puzzle.run_part_1(input); };

    run();
}

TEST_F(PuzzleTest, Puzzle17_2) {
    name = "17_2";
    expected = 94;

    day17::Input17 input(name, 10);
    init_input(input);

    day17::Puzzle17 puzzle{};

    run_puzzle = [&input, &puzzle]() { return puzzle.run_part_2(input); };

    run();
}
