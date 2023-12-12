#define DAY4

#include <vector>
#include <ranges>
#include <iostream>

#include "process_input.h"
#include "puzzle4.h"


Scratchcard::Scratchcard(std::vector<int> winning_numbers, std::vector<int> numbers)
    : winning_numbers(winning_numbers), numbers(numbers) {};


int Scratchcard::get_points(){
    int matches = get_matches();
    if (matches == 0) {
        return 0;
    }
    else {
        return 1 << (matches - 1);
    }
};

int Scratchcard::get_matches() {
    int matches = 0;

    for (int n : numbers) {
        if (std::ranges::find(winning_numbers, n) != winning_numbers.end()) {
            matches++;
        }
    }
    return matches;
};

int run_puzzle_4(Input4 &input) {
    int points = 0;

    for (auto &sc : input.scratchcards) {
        points += sc.get_points();
    }

    std::cout << "------------- Puzzle 4 -----------" << std::endl; //TODO this can be generalised
    std::cout << "Points: " << points << "\n";
    return points;
}
