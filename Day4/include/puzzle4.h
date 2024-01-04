#include <optional>

#include "io.h"
#include "puzzle.h"

namespace day4 {
    class Scratchcard {
        public:
        std::vector<int> winning_numbers;
        std::vector<int> numbers;

        Scratchcard(std::vector<int> winning_numbers, std::vector<int> numbers);
        int get_points();
        int get_matches();

        private:
        std::optional<int> points;
    };

    class SratchcardPileProcessor {
    public:
        int get_points(std::vector<day4::Scratchcard> &scratchcards);
    private:
        void set_num_copies(std::vector<unsigned> &num_copies, unsigned i, unsigned matches, unsigned times);
    };

    struct Input4 : Input {
        std::vector<day4::Scratchcard> scratchcards;

        private:
        void set_content(std::vector<std::string> lines) override;
        public:
        using Input::Input;
    };

    class Puzzle4 : public Puzzle<Input4> {
    public:
        Puzzle4() : Puzzle<Input4>("4") {};

        /// @brief Run the first part of day 4's puzzle.
        /// @param input TODO
        /// @return
        int run_part_1(Input4 &input) override;

        /// @brief Run the second part of the day 4's puzzle
        /// @param input
        /// @return
        int run_part_2(Input4 &input) override;
    };
}