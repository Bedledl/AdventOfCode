#include "io.h"


class Scratchcard {
    public:
    std::vector<int> winning_numbers;
    std::vector<int> numbers;

    Scratchcard(std::vector<int> winning_numbers, std::vector<int> numbers);
    int get_points();

    private:

    int get_matches();
};


struct Input4 : Input {
    std::vector<std::shared_ptr<Scratchcard>> scratchcards; //unique??

    private:
    void set_content(std::vector<std::string> lines) override;
    public:
    using Input::Input;
};

int run_puzzle_4(Input4 *input);
