#define DAY4

#include <vector>
#include <ranges>
#include <iostream>
#include <ranges>
#include <algorithm>

#include "process_input.h"
#include "puzzle2.h"

bool day2::Game::fits(int blue, int green, int red) {
    if (blue < max_blue) {
        return false;
    }

    if (green < max_green ) {
        return false;
    }

    if (red < max_red ) {
        return false;
    }

    return true;
}


int run_puzzle_2(Input2 &input) {
    const int green_avail = 13;
    const int blue_avail = 14;
    const int red_avail = 12;
    int points = 0;

    for (auto &game : input.games ) {
        if (game.fits(blue_avail, green_avail, red_avail)) {
            points += game.get_id();
        }
    }

    std::cout << "------------- Puzzle 2 -----------" << std::endl; //TODO this can be generalised
    std::cout << "Points: " << points << "\n";
    return points;
}
