#include <iostream>

#include "Day1/include/puzzle1.h"
#include "Day2/include/puzzle2.h"
#include "Day4/include/puzzle4.h"

constexpr std::string input_files_dir()  { return INPUT_FILES_DIR; };

std::string input_file(std::string puzzle_name) {
    return input_files_dir() + "input" + puzzle_name + ".txt";
}

bool input_file_avail(std::string puzzle_name) {
    return std::filesystem::exists(input_file(puzzle_name));
}

void init_input(Input &input) {
    if (input_file_avail(input.puzzle_name)){
        input.init_from_file(input_file(input.puzzle_name));
    }
    else {
        input.init_from_stream(std::cin);
    }
}

int main(void) {
    std::cout << "These are my solutions for the Advent of Code 2023 games!\n";

    // This is currently very un-beautiful
    day1::Input1 input1("1");
    init_input(input1);
    day1::Puzzle1 puzzle1 = day1::Puzzle1();
    puzzle1.run_part_1(input1);
    puzzle1.run_part_2(input1);
    day2::Input2 input2 =day2:: Input2("2");
    init_input(input2);
    run_puzzle_2_1(input2);
    run_puzzle_2_2(input2);

    Input4 input4 = Input4("4");
    init_input(input4);
    run_puzzle_4(input4);

}
