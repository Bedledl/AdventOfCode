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


int day17::ShortestDistanceFinder::find_shortest_path(
    Map &map, int startx, int starty, int endx, int endy) {

    auto queue = DijkstraQueue<Path, PathComparator>();
    auto start = map.get_at(startx, starty);

    if (!start) {
        throw std::runtime_error("Start field not found in map!");
    }

    start->make_start();
    for (auto dir : {Direction::East, Direction::South}) {
        auto path = new Path(0, 0);

        auto neighbor = map.get_neighbor(*start, dir);

        if (!neighbor) {
            continue;
        }
        path->move(dir, neighbor->get_heatloss());
        queue.update(path, true);
    }

    while(!queue.empty()) {
        auto current = queue.pop();
        auto coordinates = current->get_coordinates();
        for (auto dir : {Direction::North, Direction::East, Direction::South, Direction::West}) {

            if (current->is_opposite_direction(dir)) {
                continue;
            }

            if(!current->keeps_at_least_x_blocks_rule(dir, min_same_dir)) {
                continue;
            }
            if (!current->keeps_x_blocks_rule(dir, max_same_dir)){
                continue;
            }
            auto neighbor = map.get_neighbor(coordinates.first, coordinates.second, dir);
            if (!neighbor) {
                continue;
            }

            int moved_in_dir = (dir == current->get_direction()) ? current->get_moved_in_dir() + 1 : 1;
            if (moved_in_dir >= min_same_dir) {

                if (!neighbor->update_highscores(dir, moved_in_dir, current->get_shortest_distance())) {
                    continue;
                }
            }

            auto path_copy = new Path(*current);
            path_copy->move(dir, neighbor->get_heatloss());

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
