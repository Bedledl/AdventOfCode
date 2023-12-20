#include <vector>
#include <bitset>
#include <cmath>
#include <regex>
#include <numeric>
#include <ranges>
#include <algorithm>
#include <string>

#include <process_input.h>
#include "puzzle12.h"


int day12::SpringRecord::get_num_possible_arangements()
{
    std::vector<day12::Path> paths = {Path()};

    for(const char &c : damaged_record) {

        switch (c) {
            case '#':
                paths.erase(std::remove_if(paths.begin(), paths.end(),
                    [this](Path &path) { return !path.would_fit_with_hashtag(this->expected_groups); }), paths.end() );
                std::for_each(paths.begin(), paths.end(), [](Path &path){ path.add_hashtag(); });
    	        break;
            case '.':
                paths.erase( std::remove_if(paths.begin(), paths.end(),
                    [this](Path &path) {  return !path.would_fit_with_dot(this->expected_groups); }), paths.end() );
                std::for_each(paths.begin(), paths.end(), [](Path &path){ path.add_dot(); });
                break;
            case '?':
                std::vector<day12::Path> new_paths;
                for (Path &path : paths) {
                    bool fit_with_dot = path.would_fit_with_dot(this->expected_groups);
                    bool fit_with_hash = path.would_fit_with_hashtag(this->expected_groups);

                    if (!(fit_with_dot || fit_with_hash)) {
                        continue;
                    }

                    if (fit_with_dot && fit_with_hash) {
                        Path path_add_hash = path;
                        path.add_dot();
                        path_add_hash.add_hashtag();

                        new_paths.emplace_back(std::move(path_add_hash));
                    }
                    else if (fit_with_dot)
                    {
                        path.add_dot();
                    }
                    else if (fit_with_hash)
                    {
                        path.add_hashtag();
                    }
                    new_paths.emplace_back(std::move(path));
                }
                paths = new_paths;
                break;
        }
    }

    for (Path &path : paths) {
        path.add_dot();
    }

    return std::count_if(paths.begin(), paths.end(), [this](Path &path) { return path.fits_accuratly(this->expected_groups); });
}

int day12::Puzzle12::run_part_1(Input12 &input)
{
    int points = 0;
    for (SpringRecord &record : input.records)
    {
        points += record.get_num_possible_arangements();
    }

    return points;
}

int day12::Puzzle12::run_part_2(Input12 &input)
{
    int points = 0;
    for (SpringRecord &record : input.records_unfolded)
    {
        points += record.get_num_possible_arangements();
    }

    std::cout << points << std::endl;
    return points;
}
