#include <string>
#include <vector>

#include "puzzle12_bf.h"
#include "process_input.h"

void day12_bf::Input12::set_content(std::vector<std::string> lines)
{
    for (const std::string &line : lines)
    {
        std::vector<std::string> split_record = split(line, " ");

        std::vector<int> groups = get_numbers_from_string(split_record[1], ",");

        std::string unfolded_record_str = "";
        std::vector<int> groups_unfolded;
        for (int i = 0; i < 5; ++i)
        {
            unfolded_record_str += split_record[0];
            if (i < 4) {
                unfolded_record_str += "?";
            }

            groups_unfolded.insert(groups_unfolded.end(), groups.begin(), groups.end());
        }

        records.emplace_back(std::move(split_record[0]), std::move(groups));

        records_unfolded.emplace_back(std::move(unfolded_record_str), std::move(groups_unfolded));
    }
}
