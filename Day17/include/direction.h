#include <optional>
#include <stdexcept>

namespace day17
{
    /// @brief Enum which defines the directions in which the Lava can flow.
    enum class Direction {
        None, North, East, South, West
    };

    constexpr std::optional<day17::Direction> get_opposite_direction(day17::Direction dir) {
        switch (dir)
        {
        case day17::Direction::North:
            return day17::Direction::South;
            break;

        case day17::Direction::South:
            return day17::Direction::North;
            break;

        case day17::Direction::East:
            return day17::Direction::West;
            break;

        case day17::Direction::West:
            return day17::Direction::East;
            break;

        default:
            return {};
        }
    }

    constexpr char get_char_to_direction(day17::Direction dir) {
        switch (dir)
        {
        case day17::Direction::North:
            return '^';
            break;

        case day17::Direction::South:
            return 'v';
            break;

        case day17::Direction::East:
            return '>';
            break;

        case day17::Direction::West:
            return '<';
            break;

        default:
            throw std::runtime_error("Cannot get opposite direction of this direction");
            break;
        }
    }
} // namespace day17
