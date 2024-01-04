
#include <string>

#include "io.h"
#include "puzzle.h"

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

struct Input2 : Input {
    std::vector<day2::Game> games;
    private:
    void set_content(std::vector<std::string> lines) override;
    public:
    using Input::Input;
};


    class Puzzle2 : public Puzzle<Input2> {
        public:
        Puzzle2() : Puzzle<Input2>("2") {};

        /// @brief Run the first part of day 1's puzzle.
        /// @param input TODO
        /// @return
        int run_part_1(Input2 &input) override;

        /// @brief Run the second part of the day 1's puzzle
        /// @param input
        /// @return
        int run_part_2(Input2 &input) override;
    };

}
