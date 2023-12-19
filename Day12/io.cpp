#include <string>
#include <vector>

#include "puzzle12.h"
#include "process_input.h"

void day12::Input12::set_content(std::vector<std::string> lines)
{
    for (const std::string &line : lines)
    {
        std::vector<std::string> split_record = split(line, " ");

        std::vector<int> groups = get_numbers_from_string(split_record[1], ",");

        records.emplace_back(std::move(split_record[0]), groups);
    }
}
