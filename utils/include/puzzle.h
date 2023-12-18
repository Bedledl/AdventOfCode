#ifndef PUZZLE_H
#define PUZZLE_H

#include <string>
#include <iostream>

#include "io.h"


/// @brief Interface for Puzzle classes. At deriving the respective Input class should be bound.
/// @tparam I Respective Input class for the Puzzle
template<typename I>
class Puzzle {
    public:
    Puzzle(std::string puzzle_name) : puzzle_name(puzzle_name) {};
    virtual ~Puzzle() = default;
    virtual int run_part_1(I &input) = 0;
    virtual int run_part_2(I &input) = 0;
    void run_and_print_puzzle(I &input, Output &outout) {
        std::cout << "Print Test" << std::endl;
    };
    private:
    std::string puzzle_name;
};

#endif
