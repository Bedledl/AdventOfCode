#include <string>

#include "io.h"

namespace day1 {
struct Calibration {
    Calibration(std::string calibration_text);
    std::array<int, 2> get_value(bool include_nr_strings);
    private:
        std::string calibration_text;
};

struct Input1 : Input {
    std::vector<day1::Calibration> calibrations;

    private:
    void set_content(std::vector<std::string> lines) override;
    public:
    using Input::Input;
};

int run_puzzle_1_1(Input1 &input);
int run_puzzle_1_2(Input1 &input);

}
