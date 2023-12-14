#include <string>
#include <vector>
#include <array>
#include <algorithm>

#include <iostream>//only for debugging

#include "puzzle2.h"
#include "process_input.h"



inline int get_id(const std::string &game_id_str) {
    std::vector<std::string> game_id_split = split(game_id_str, " ");

    return std::stoi(game_id_split[1]);;
}

int get_max_num_colored_balls(const std::string & find_in, std::string color) {
    int max_num = 0, curr_num = 0;

    std::vector<std::string> split_at_spaces = split(find_in, " ");

    for (unsigned i=1; i < split_at_spaces.size(); i+=2) {
        std::string &curr_color = split_at_spaces[i];

        if (curr_color.find(color) == std::string::npos) {
            continue;
        }

        curr_num = std::stoi(split_at_spaces[i-1]);
        max_num = std::max(curr_num, max_num);
    }

    return max_num;
}

void Input2::set_content(std::vector<std::string> lines) {

    int id;

    for (const std::string &line : lines) {
        std::vector<std::string> colon_split = split(line, ":");

        id = get_id(std::move(colon_split[0]));

        int green_max_num = get_max_num_colored_balls(colon_split[1], "green");
        int red_max_num = get_max_num_colored_balls(colon_split[1], "red");
        int blue_max_num = get_max_num_colored_balls(colon_split[1], "blue");

        games.emplace_back(
            day2::Game(id, green_max_num, red_max_num, blue_max_num)
        );
    }
}
