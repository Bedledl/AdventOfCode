#include <vector>
#include <bitset>
#include <cmath>
#include <regex>
#include <numeric>
#include <ranges>
#include <algorithm>
#include <string>

#include <process_input.h>
#include "puzzle17.h"

#include <unistd.h>


[[nodiscard]] unsigned day17::ShortestDistanceFinder::find_shortest_path(
    Map &map, uint8_t startx, uint8_t starty, uint8_t endx, uint8_t endy) {

    auto queue = DijkstraQueue<Path, PathComparator>();
    auto start = map.get_at(startx, starty);

    if (!start) {
        throw std::runtime_error("Start field not found in map!");
    }

    start->make_start();

    auto path = new Path(0, 0);
    queue.update(path, true);

    while(!queue.empty()) {
        auto current = queue.pop();
        for (auto dir : {Direction::North, Direction::East, Direction::South, Direction::West}) {

            if (current->is_opposite_direction(dir)) {
                continue;
            }

            if (!current->keeps_x_blocks_rule(dir, max_same_dir)){
                continue;
            }

            uint8_t try_n_moves = (dir != current->get_direction()) ? min_same_dir : 1;

            // This is just for early break
            auto coordinates = current->get_coordinates();
            if (!map.get_neighbor(coordinates.first, coordinates.second, dir, try_n_moves)) {
                continue;
            }

            auto path_copy = new Path(*current);
            day17::Field *neighbor = NULL;

            for (uint8_t i=0; i<try_n_moves; ++i) {
                auto coordinates = path_copy->get_coordinates();
                neighbor = map.get_neighbor(coordinates.first, coordinates.second, dir);
                if (!neighbor) {
                    break;
                }

                path_copy->move(dir, neighbor->get_heatloss());
            }

            if (!neighbor) {
                continue;
            }

            if (!neighbor->update_highscores(dir, path_copy->get_moved_in_dir(), path_copy->get_shortest_distance())) {
                    continue;
            }

            queue.update(path_copy, true);
        }

        delete current;
    }

    auto end_field = map.get_at(endx, endy);
    if (end_field) {
        return end_field->get_shortest_distance();
    }
    throw std::runtime_error("End field was not found?");
};


int day17::Puzzle17::run_part_1(day17::Input17 &input)
{
    ShortestDistanceFinder pathfinder{1, 3};
    return pathfinder.find_shortest_path(*input.map, 0, 0, input.map->size_x-1, input.map->size_y-1);
}

int day17::Puzzle17::run_part_2(day17::Input17 &input)
{
    ShortestDistanceFinder pathfinder{4, 10};
    return pathfinder.find_shortest_path(*input.map, 0, 0, input.map->size_x-1, input.map->size_y-1);
}
