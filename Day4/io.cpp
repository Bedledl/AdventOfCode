#include <string>
#include <vector>
#include <array>
#include <algorithm>

#include <iostream>//only for debugging

#include "puzzle4.h"
#include "process_input.h"

std::array<std::string, 2> get_numbers_substrings(const std::string &line) {

    std::vector<std::string> split_at_colon = split(line, ":");
    std::vector<std::string> split_at_dash = split(split_at_colon[1], "|");

    return std::array<std::string, 2> {split_at_dash[0], split_at_dash[1]};
}

void Input4::set_content(std::vector<std::string> &lines) {
    std::vector<int> winning_numbers;
    std::vector<int> player_numbers;

    for (const std::string &line : lines) {
         std::array<std::string, 2> number_strings = get_numbers_substrings(line);

        winning_numbers = get_numbers_from_string(number_strings[0]);
        player_numbers = get_numbers_from_string(number_strings[1]);

        scratchcard = new Scratchcard(
            winning_numbers,
            player_numbers
        );

        this->scratchcards.push_back(std::shared_ptr<Scratchcard>(scratchcard));
    }
}
