#include "puzzle17.h"

[[nodiscard]] bool day17::Path::is_smaller_than(day17::Path &path) const {
            if (min_distance == path.min_distance) {
                if (moved_in_dir == path.moved_in_dir) {
                    if (x == path.x) {
                        if (y == path.y) {
                            if (int(current_direction) == int(path.current_direction)) {
                                return false;
                            }
                            return int(current_direction) < int(path.current_direction);
                            return false;
                        }
                        return y > path.y;
                    }
                    return x > path.x;
                }
                return moved_in_dir < path.moved_in_dir;
            }
            return min_distance < path.min_distance;
        }

void day17::Path::move(Direction dir, uint8_t additional_heatloss) {
    switch(dir) {
        case Direction::North:
            --x;
            break;
        case Direction::South:
            ++x;
            break;
        case Direction::East:
            ++y;
            break;
        case Direction::West:
            --y;
            break;
        default:
            throw std::runtime_error("Tried to move path in unknown direction");
    }

    min_distance += additional_heatloss;
    if (dir == current_direction) {
        ++moved_in_dir;
    }
    else {
        current_direction = dir;
        moved_in_dir = 1;
    }
}
