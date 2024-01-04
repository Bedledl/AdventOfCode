#define DAY4

#include <vector>
#include <ranges>
#include <iostream>

#include "process_input.h"
#include "puzzle4.h"


day4::Scratchcard::Scratchcard(std::vector<int> winning_numbers, std::vector<int> numbers)
    : winning_numbers(winning_numbers), numbers(numbers) {};


int day4::Scratchcard::get_points(){
    if (points) {
        return points.value();
    }

    int matches = get_matches();
    if (matches == 0) {
        points = 0;
    }
    else {
        points = 1 << (matches - 1);
    }

    return points.value();
};

int day4::Scratchcard::get_matches() {
    int matches = 0;

    for (int n : numbers) {
        if (std::ranges::find(winning_numbers, n) != winning_numbers.end()) {
            matches++;
        }
    }
    return matches;
};

int day4::Puzzle4::run_part_1(Input4 &input) {
    int points = 0;

    for (auto &sc : input.scratchcards) {
        points += sc.get_points();
    }
    return points;
}

int day4::Puzzle4::run_part_2(Input4 &input) {
    day4::SratchcardPileProcessor pileProcessor;
    return pileProcessor.get_points(input.scratchcards);
}
