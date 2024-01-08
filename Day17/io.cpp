#include <string>
#include <vector>

#include "puzzle17.h"
#include "process_input.h"

void day17::Input17::set_content(std::vector<std::string> lines)
{
    std::vector<std::vector<uint8_t>> int_map(lines.size());

    for (uint8_t i=0; i<lines.size(); ++i) {
        int_map[i].resize(lines[i].size());
        for (uint8_t j=0; j<lines[i].size(); ++j) {
            int_map[i][j] = lines[i][j] - '0';
        }

    }

    map = std::make_unique<Map>(int_map, max_same_dir);
}
