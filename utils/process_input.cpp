/* This file provides functionality to process inputs for advent of code games */
#include <functional>
#include <algorithm>

#include <iostream>

#include "include/process_input.h"

std::vector<std::string> split (const std::string &input, std::string const &delimiter) {
    std::function<std::vector<std::string> &(const std::string &, std::vector<std::string> &)> split_impl;
    split_impl = 
    [delimiter, &split_impl]
    (const std::string &str, std::vector<std::string> &split_str) -> std::vector<std::string> &
    {
        auto found = str.find(delimiter);

        const std::string &substr = str.substr(0, found);

        if (substr.size() > 0){
            split_str.emplace_back(std::move(substr));
        }

        if(found == std::string::npos) {
            return split_str;
        }

        const std::string &residual_str = str.substr(found + delimiter.length());


        //i think i don't need a move then here, do we?
        return split_impl(residual_str, split_str);
    };

    std::vector<std::string> split_str = {};
    return split_impl(input, split_str);
}

/*  parse string containing numbers delimited by spaces, e.g. "45 7 90 1"*/
std::vector<int> get_numbers_from_string(std::string &numbers_string) {
    std::vector<int> numbers;

    std::vector<std::string> split_numbers_string = split(numbers_string, " ");

    std::ranges::transform(split_numbers_string, std::back_inserter(numbers), [](std::string maybe_number_string) {
        return std::stoi(maybe_number_string);
    });

    return numbers;
}

