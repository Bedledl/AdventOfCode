#include <string>
#include <vector>
#include <array>
#include <algorithm>

#include <iostream>//only for debugging

#include "puzzle1.h"
#include "process_input.h"


void Input1::set_content(std::vector<std::string> &lines) {

    for (std::string &line : lines) {
        // uses rvalue with emplace_back and move operation
        calibrations.emplace_back(Calibration(std::move(line)));
    }
}
