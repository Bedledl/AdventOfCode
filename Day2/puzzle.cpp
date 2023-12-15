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

int day2::Game::get_max(Color color) {
    switch(color) {
        case Color::red:
            return max_red;
        case Color::blue:
            return max_blue;
        case Color::green:
            return max_green;
        default:
            throw std::runtime_error("Color is not available in this game");
    }
}


int run_puzzle_2_1(Input2 &input) {
    const int green_avail = 13;
    const int blue_avail = 14;
    const int red_avail = 12;
    int points = 0;

    for (auto &game : input.games ) {
        if (game.fits(blue_avail, green_avail, red_avail)) {
            points += game.get_id();
        }
    }

    std::cout << "------------- Puzzle 2 Part 1 -----------" << std::endl; //TODO this can be generalised
    std::cout << "Points: " << points << "\n";
    return points;
}

int run_puzzle_2_2(Input2 &input) {
    int points = 0;

    for (auto &game : input.games ) {
        int max_blue = game.get_max(day2::Color::blue);
        int max_red = game.get_max(day2::Color::red);
        int max_green = game.get_max(day2::Color::green);
        points += max_blue * max_green * max_red;
    }

    std::cout << "------------- Puzzle 2 Part 2 -----------" << std::endl; //TODO this can be generalised
    std::cout << "Points: " << points << "\n";
    return points;
}
