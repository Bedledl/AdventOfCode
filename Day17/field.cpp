#include "puzzle17.h"
#include <array>

bool day17::Field::update_highscores(Direction dir, uint8_t moved_in_dir, unsigned distance_until_now) {
    bool updated = false;
    for (uint8_t i=moved_in_dir-1; i<max_same_dir; ++i) {
        if (distance_until_now < highscores[dir][i]) {
            updated = true;
            highscores[dir][i] = distance_until_now;
        }
    }
    return updated;
}

day17::Field::Field(uint8_t x, uint8_t y, uint8_t heatloss, uint8_t max_same_dir) : x(x), y(y), heatloss(heatloss), max_same_dir(max_same_dir) {
    for (auto &dir : {Direction::North, Direction::South, Direction::West, Direction::East}) {
        highscores[dir] = std::vector<unsigned>(max_same_dir, std::numeric_limits<unsigned>::max());
    }
};

void day17::Field::make_start() {
    for (auto &dir : {Direction::North, Direction::South, Direction::West, Direction::East}) {
        std::fill(highscores[dir].begin(), highscores[dir].end(), 0);
    }
}

[[nodiscard]] unsigned day17::Field::get_shortest_distance() const {
    auto min_value = std::numeric_limits<unsigned>::max();
    for (const auto & [key, value] : highscores) {
        auto min_value_for_dir = std::min_element(value.begin(), value.end());
        min_value = std::min(min_value, *min_value_for_dir);
    }
    return min_value;
}
