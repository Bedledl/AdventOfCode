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


int day17::ShortestDistanceFinder_UpTo3::find_shortest_path(
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
        // queue.print([](Path &path){
        //     auto coords = path.get_coordinates();
        //     std::cout << "("<< coords.first << ", " << coords.second << ")[" << path.get_shortest_distance() << ", " << path.get_moved_in_dir() << get_char_to_direction(path.get_direction()) <<  "]" << ", "; });

        auto current = queue.pop();
        auto coordinates = current->get_coordinates();
        for (auto dir : {Direction::North, Direction::East, Direction::South, Direction::West}) {
            if (coordinates.first == 0 && coordinates.second == 5&& dir == Direction::East) {
                std::cout << "lets see if we can move further" << std::endl;
            }

            if (current->is_opposite_direction(dir)) {
                continue;
            }

            if (coordinates.first == 0 && coordinates.second == 5&& dir == Direction::East) {
                std::cout << "ok its not the opposite direction" << std::endl;
            }

            if (!current->keeps_x_blocks_rule(dir, 3))
                continue;

            if (coordinates.first == 0 && coordinates.second == 5&& dir == Direction::East) {
                std::cout << "keeps three block rule" << std::endl;
            }

            auto neighbor = map.get_neighbor(coordinates.first, coordinates.second, dir);
            if (!neighbor) {
                continue;
            }

            if (coordinates.first == 0 && coordinates.second == 5&& dir == Direction::East) {
                std::cout << "neighbort was also found" << std::endl;
            }

            int moved_in_dir = (dir == current->get_direction()) ? current->get_moved_in_dir() + 1 : 1;
            if (!neighbor->update_highscores(dir, moved_in_dir, current->get_shortest_distance())) {
                continue;
            }

            if (coordinates.first == 0 && coordinates.second == 5&& dir == Direction::East) {
                std::cout << "did update" << std::endl;
            }

            auto path_copy = new Path(*current);
            path_copy->move(dir, neighbor->get_heatloss());

            if (coordinates.first == 0 && coordinates.second == 5&& dir == Direction::East) {
                std::cout << "new path" << std::endl;
            }

            queue.update(path_copy, true);
            if (coordinates.first == 0 && coordinates.second == 5&& dir == Direction::East) {
                std::cout << "update" << std::endl;
            }
        }

        delete current;
    }

    auto end_field = map.get_at(endx, endy);
    if (end_field) {
        return end_field->get_shortest_distance();
    }
    throw std::runtime_error("End field was not found?");
};


int day17::ShortestDistanceFinder_4To10::find_shortest_path(
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
        // queue.print([](Path &path){
        //     auto coords = path.get_coordinates();
        //     if (coords.first < 141 || coords.second < 141) {
        //         return;
        //     }

        //     std::cout << "("<< coords.first << ", " << coords.second << ")[" << path.get_shortest_distance() << ", " << path.get_moved_in_dir() << "]" << ", "; });

        auto current = queue.pop();
        auto coordinates = current->get_coordinates();
        for (auto dir : {Direction::North, Direction::East, Direction::South, Direction::West}) {

            if (current->is_opposite_direction(dir)) {
                continue;
            }

            if(!current->keeps_at_least_x_blocks_rule(dir, 4)) {
                continue;
            }
            if (!current->keeps_x_blocks_rule(dir, 10)){
                continue;
            }
            auto neighbor = map.get_neighbor(coordinates.first, coordinates.second, dir);
            if (!neighbor) {
                continue;
            }

            int moved_in_dir = (dir == current->get_direction()) ? current->get_moved_in_dir() + 1 : 1;
            if (moved_in_dir >= 4) {

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
    ShortestDistanceFinder_UpTo3 pathfinder;
    return pathfinder.find_shortest_path(*input.map, 0, 0, input.map->size_x-1, input.map->size_y-1);
}

int day17::Puzzle17::run_part_2(day17::Input17 &input)
{
    ShortestDistanceFinder_4To10 pathfinder;
    return pathfinder.find_shortest_path(*input.map, 0, 0, input.map->size_x-1, input.map->size_y-1);
}
