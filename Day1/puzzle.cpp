#define DAY4

#include <vector>
#include <ranges>
#include <iostream>
#include <ranges>
#include <algorithm>
#include <map>
#include <functional>

#include "process_input.h"
#include "puzzle1.h"


const std::map<std::string, int> map_nr_strings() {
    return std::map<std::string, int>{{"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};
};

const std::map<std::string, int> map_nr() {
    return std::map<std::string, int>{{"1", 1}, {"2", 2}, {"3", 3}, {"4", 4}, {"5", 5}, {"6", 6}, {"7", 7}, {"8", 8}, {"9", 9}};
};

std::array<int, 4> find_first_last_nr(const std::string &text, const std::map<std::string, int> &map_nr) {
    auto found_first_at = text.size();
    int found_first = -1;

    auto found_last_at = -1;
    int found_last = -1;

    for (auto const& [str, num] : map_nr) {
        int curr_found_at = text.find(str);
        if (curr_found_at < found_first_at) {
            found_first = num;
            found_first_at = curr_found_at;
        }

        curr_found_at = text.rfind(str);
        if (curr_found_at > found_last_at) {
            found_last = num;
            found_last_at = curr_found_at;
        }
    }

    return std::array<int, 4>{found_first, int(found_first_at), found_last, found_last_at};
};



day1::Calibration::Calibration(std::string calibration_text) : calibration_text(calibration_text) {

};

std::array<int, 2> day1::Calibration::get_value(bool include_nr_strings) {
    auto first_last_nr = find_first_last_nr(calibration_text, map_nr());

    if (include_nr_strings) {
        auto first_last_nr_with_nr_strings = find_first_last_nr(calibration_text, map_nr_strings());
        if(first_last_nr_with_nr_strings[1] < first_last_nr[1]) { first_last_nr[0] = first_last_nr_with_nr_strings[0]; }
        if(first_last_nr_with_nr_strings[3] > first_last_nr[3]) { first_last_nr[2] = first_last_nr_with_nr_strings[2]; }
    }
    
    if (first_last_nr[0] < 0 || first_last_nr[2] < 0) {
        throw std::runtime_error("No number was found in Calibraton String");
    }

    return std::array<int, 2>{first_last_nr[0], first_last_nr[2]};
}

int day1::Puzzle1::run_part_1(Input1 &input) {
    int points = 0;

    for (auto &cal : input.calibrations) {
        auto first_last_number = cal.get_value(false);
        points += 10 * first_last_number[0] + first_last_number[1];
    }

    return points;
}

int day1::Puzzle1::run_part_2(Input1 &input) {
    int points = 0;

    for (auto &cal : input.calibrations) {
        auto first_last_number = cal.get_value(true);
        points +=  10 * first_last_number[0] + first_last_number[1];
    }

    return points;
}
