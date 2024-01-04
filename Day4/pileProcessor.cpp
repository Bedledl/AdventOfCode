#include <numeric>

#include "puzzle4.h"

int day4::SratchcardPileProcessor::get_points(std::vector<day4::Scratchcard> &scratchcards) {
    std::vector<unsigned> num_copies = std::vector<unsigned>(scratchcards.size(), 1);
    for (size_t i=0; i<scratchcards.size(); ++i) {
        set_num_copies(num_copies, i, scratchcards[i].get_matches(), num_copies[i]);
    }

    return std::reduce(num_copies.begin(), num_copies.end());
}

void day4::SratchcardPileProcessor::set_num_copies(std::vector<unsigned> &num_copies, unsigned i, unsigned matches, unsigned times) {
    size_t j = i + 1;
    while (j < num_copies.size() && j <= i + matches) {
        num_copies[j] += times;
        ++j;
    }
}
