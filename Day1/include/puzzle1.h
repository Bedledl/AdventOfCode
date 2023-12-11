#include <string>

#include "io.h"

struct Calibration {
    Calibration(std::string calibration_text) : calibration_text(calibration_text) {};
    int get_value();
    private:
        std::string calibration_text;
        int get_first_number();
        int get_last_number();
};

struct Input1 : Input {
    std::vector<std::shared_ptr<Calibration>> calibrations;

    private:
    void set_content(std::vector<std::string> lines) override;
    public:
    using Input::Input;
};

int run_puzzle_1(Input1 *input);

