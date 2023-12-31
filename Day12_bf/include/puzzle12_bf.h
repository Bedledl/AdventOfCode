#include <string>
#include <regex>

#include "io.h"
#include "puzzle.h"

namespace day12_bf
{

    /// @brief Represents one line of the puzzle's input and provides methods to calculate the puzzle's result
    class SpringRecord
    {
    private:
        const std::string damaged_record;
        const std::vector<int> group_of_dmgd_springs;

        const std::vector<int> get_broken_indices();
        const std::vector<std::string> get_records_permutations();
        const std::regex get_regex();

    public:
        SpringRecord(std::string record, std::vector<int> group_of_dmgd_springs) : damaged_record(record), group_of_dmgd_springs(group_of_dmgd_springs) {};
        /// @brief Calculates the numbers of possible arangements that fit the given group lengths
        /// @return Number of possible fitting aragements
        int get_num_possible_arangements();
    };

    struct Input12 : Input
    {
        std::vector<day12_bf::SpringRecord> records;
        std::vector<day12_bf::SpringRecord> records_unfolded;

    private:
        void set_content(std::vector<std::string> lines) override;

    public:
        using Input::Input;
    };

    class Puzzle12 : Puzzle<Input12>
    {
    public:
        Puzzle12() : Puzzle<Input12>("12"){};

        /// @brief Run the first part of day 12's puzzle.
        /// @param input TODO
        /// @return
        int run_part_1(Input12 &input) override;

        /// @brief Run the second part of the day 12's puzzle
        /// @param input
        /// @return
        int run_part_2(Input12 &input) override;
    };
}
