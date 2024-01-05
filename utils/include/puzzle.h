#ifndef PUZZLE_H
#define PUZZLE_H

#include <string>
#include <iostream>

#include "io.h"

#include <chrono>
#include <utility>
#include <cstdlib>

typedef std::chrono::high_resolution_clock::time_point TimeVar;

#define duration(a) std::chrono::duration_cast<std::chrono::milliseconds>(a).count()
#define timeNow() std::chrono::high_resolution_clock::now()

template<typename F, typename... Args>
double funcTime(F func, Args&&... args){
    TimeVar t1=timeNow();
    func(std::forward<Args>(args)...);
    return duration(timeNow()-t1);
}

/// @brief Interface for Puzzle classes. At deriving the respective Input class should be bound.
/// @tparam I Respective Input class for the Puzzle
template<typename I>
class Puzzle {
    public:
    Puzzle(std::string puzzle_name) : puzzle_name(puzzle_name) {};
    virtual ~Puzzle() = default;
    virtual int run_part_1(I &input) = 0;
    virtual int run_part_2(I &input) = 0;
    int get_time_to_run_1(I &input) { return funcTime([&input, this](){this->run_part_1(input);}); }
    int get_time_to_run_2(I &input) { return funcTime([&input, this](){this->run_part_2(input);}); }
    void run_and_print_puzzle(I &input, Output &outout) {
        std::cout << "Print Test" << std::endl;
    };
    void print_result(int part, int result) {
        std::cout << "------------- Puzzle " << puzzle_name<<" Part "<< part <<" -----------" << std::endl;
        std::cout << "Points: " << result << "\n";
    };
    private:
    std::string puzzle_name;
};

#endif
