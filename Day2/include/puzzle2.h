
#include <string>

#include "io.h"

namespace day2  {
    enum class Color { red, blue, green };
    struct Game {
        bool fits(int blue, int green, int red);
        int get_id() const { return id; };
        int get_max(Color color);
        Game(int id, int max_green, int max_red, int max_blue)
        : id(id), max_blue(max_blue), max_green(max_green), max_red(max_red) {};
        private:
            int id;
            int max_blue;
            int max_green;
            int max_red;
    };
}

struct Input2 : Input {
    std::vector<day2::Game> games;
    private:
    void set_content(std::vector<std::string> lines) override;
    public:
    using Input::Input;
};

int run_puzzle_2_1(Input2 &input);
int run_puzzle_2_2(Input2 &input);
