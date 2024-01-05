#include <iostream>

#include "Day1/include/puzzle1.h"
#include "Day2/include/puzzle2.h"
#include "Day4/include/puzzle4.h"
#include "Day12_bf/include/puzzle12_bf.h"
#include "Day12/include/puzzle12.h"
#include "Day17/include/puzzle17.h"

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
    day1::Puzzle1 puzzle1;
    puzzle1.print_result(1, puzzle1.run_part_1(input1));
    puzzle1.print_result(2, puzzle1.run_part_2(input1));

    day2::Input2 input2 = day2::Input2("2");
    init_input(input2);
    day2::Puzzle2 puzzle2;
    puzzle2.print_result(1, puzzle2.run_part_1(input2));
    puzzle2.print_result(2,  puzzle2.run_part_2(input2));

    day4::Input4 input4{"4"};
    init_input(input4);
    day4::Puzzle4 puzzle4;
    puzzle4.print_result(1, puzzle4.run_part_1(input4));
    puzzle4.print_result(2, puzzle4.run_part_2(input4));

    // day12_bf::Input12 input12_bf("12");
    // init_input(input12_bf);
    // day12_bf::Puzzle12 puzzle12_bf;
    // std::cout << puzzle12_bf.run_part_1(input12_bf) << std::endl;

    // day12::Input12 input12("12");
    // init_input(input12);
    // day12::Puzzle12 puzzle12;
    // std::cout << puzzle12.run_part_1(input12) << std::endl;
    // std::cout << puzzle12.run_part_2(input12) << std::endl;


    day17::Input17 input17_1 = day17::Input17("17", 3);
    init_input(input17_1);

    day17::Input17 input17_2 = day17::Input17("17", 10);
    init_input(input17_2);

    day17::Puzzle17 puzzle17;
    puzzle17.print_result(1, puzzle17.run_part_1(input17_1));
    puzzle17.print_result(2, puzzle17.run_part_2(input17_2));
    std::cout << puzzle17.get_time_to_run_1(input17_1) << std::endl;
    std::cout << puzzle17.get_time_to_run_2(input17_2) << std::endl;
}
