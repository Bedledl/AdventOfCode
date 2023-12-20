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

const std::vector<int> day12::SpringRecord::get_broken_indices()
{
    std::vector<int> indices;

    for (int i = 0; i < damaged_record.size(); ++i)
    {
        if (damaged_record[i] == '?')
        {
            indices.push_back(i);
        }
    }

    return indices;
}

const std::vector<std::string> day12::SpringRecord::get_records_permutations()
{
    // wrong we know the number of # in the string its:
    int num_dmgd_springs = std::reduce(group_of_dmgd_springs.begin(), group_of_dmgd_springs.end());
    // this is the numbers of # that shoudl be filled at ?
    int num_unknwn_dmgd_spring = num_dmgd_springs - std::ranges::count(damaged_record, '#');
    // indices of all unknown springs
    const std::vector<int> indices = get_broken_indices();

    std::string permutation = std::string(num_unknwn_dmgd_spring, '#') + std::string(indices.size() - num_unknwn_dmgd_spring, '.');

    std::vector<std::string> permutations = {};

    do
    {
        // fill each permutation at the indices anc add it to permutations vector
        std::string record_permutation = damaged_record;

        for (int i = 0; i < indices.size(); ++i)
        {
            record_permutation[indices[i]] = permutation[i];
        }
        permutations.push_back(record_permutation);
    } while (std::next_permutation(permutation.begin(), permutation.end()));

    return permutations;
}

const std::regex day12::SpringRecord::get_regex()
{
    std::string regex = "\\.*";

    for (int i = 0; i < group_of_dmgd_springs.size(); ++i)
    {
        int group_size = group_of_dmgd_springs[i];

        std::string group_regex = "#{" + std::to_string(group_size) + "}";

        regex += group_regex;

        if (i < group_of_dmgd_springs.size() - 1)
        {
            regex += "\\.{1,}";
        }
        else
        {
            regex += "\\.*";
        }
    }

    return std::regex(regex);
}

int day12::SpringRecord::get_num_possible_arangements()
{
    int fitting_permutations = 0;
    const std::regex regex = get_regex();
    const std::vector<std::string> records_permutations = day12::SpringRecord::get_records_permutations();
    int num_dmgd_springs = std::reduce(group_of_dmgd_springs.begin(), group_of_dmgd_springs.end());

    for (const std::string &permutation : records_permutations)
    {

        if (std::regex_match(permutation, regex))
        {
            ++fitting_permutations;
        }
    }

    return fitting_permutations;
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
