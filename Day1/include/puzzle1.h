#include <string>

#include "io.h"
#include "puzzle.h"


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

class Puzzle1 : public Puzzle<Input1> {
    public:

    Puzzle1() : Puzzle<Input1>("1") {};

    /// @brief Run the first part of day 1's puzzle.
    /// @param input TODO
    /// @return
    int run_part_1(Input1 &input) override;

    /// @brief Run the second part of the day 1's puzzle
    /// @param input
    /// @return
    int run_part_2(Input1 &input) override;
};

}
