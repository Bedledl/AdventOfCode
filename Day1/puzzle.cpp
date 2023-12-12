#define DAY4

#include <vector>
#include <ranges>
#include <iostream>
#include <ranges>
#include <algorithm>

#include "process_input.h"
#include "puzzle1.h"


int Calibration::get_first_number() {
    for (char &c : calibration_text){
        if(isdigit(c)) {
            return c - '0';
        }
    }
    throw std::runtime_error("No number was found in Calibraton String");
};

int Calibration::get_last_number() {
    std::ranges::reverse(calibration_text);
    for (char &c : calibration_text){
        if(isdigit(c)) {
            return c - '0';
        }
    }
    throw std::runtime_error("No number was found in Calibraton String");
};

int Calibration::get_value() {
    return get_first_number() * 10 + get_last_number();
}

int run_puzzle_1(Input1 &input) {
    int points = 0;

    for (auto cal : input->calibrations) {
        points += cal->get_value();
    }

    std::cout << "------------- Puzzle 1 -----------" << std::endl; //TODO this can be generalised
    std::cout << "Points: " << points << "\n";
    return points;
}
