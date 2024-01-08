#include <vector>

#include "include/puzzle17.h"
#include <unistd.h>

day17::Map::Map(std::vector<std::vector<uint8_t>> raw_map, uint8_t max_same_dir) {
    size_x = raw_map.size();
    size_y = raw_map[0].size();
    map.resize(size_x);
    for (uint8_t i=0; i< size_x; ++i) {
        auto inner_vector = raw_map[i];
        if (inner_vector.size() != size_y) {
            throw std::runtime_error(
                "Invalid Input for Puzzle 17. Line " + std::to_string(i) + " is not as long as the previous.");
        }

        for ( int j=0; j< size_y; j++) {
            map[i].emplace_back(Field(i, j, inner_vector[j], max_same_dir));
        }
    }
}

[[nodiscard]] day17::Field* day17::Map::get_neighbor(day17::Field &field, day17::Direction dir, uint8_t n) {
    auto coords = field.get_coordinates();
    return get_neighbor(coords.first, coords.second, dir, n);
}

[[nodiscard]] day17::Field* day17::Map::get_neighbor(uint8_t x, uint8_t y, day17::Direction dir, uint8_t n) {
    switch (dir)
    {
    case Direction::North:
        if (x - n >= 0 ) {
            return &map[x - n][y];
        }
        break;
    case Direction::East:
        if (y < size_y-n) {
            return &map[x][y + n];
        }
        break;
    case Direction::South:
        if (x < size_x-n) {
            return &map[x + n][y];
        }
        break;
    case Direction::West:
        if (y - n >= 0) {
            return &map[x][y - n];
        }
        break;
    case Direction::None:
        return {};
    }

    return NULL;
}

[[nodiscard]] day17::Field* day17::Map::get_at(uint8_t x, uint8_t y) {
    if (0 <= x < size_x) {
        if (0 <= y < size_y) {
            return &map[x][y];
        }
    }
    return {};
}

[[nodiscard]] day17::Field* day17::Map::get_at(std::pair<uint8_t, uint8_t> coords) {
    return get_at(coords.first, coords.second);
}

/*
void day17::Map::print_path(int x, int y) {
    std::vector<std::string> map;
    for (int x=0; x<size_x; ++x) {
        std::string s = std::string(size_y, ' ');
        s += "\n";
        map.push_back(s);
    }

    int path_length = 0;

    std::shared_ptr<Field> current_field;
    if (auto f = get_at(x, y)){
        current_field = f.value();
    }
    else {
        std::cout << "print path: did not find end field." << std::endl;
        return;
    }

    map[x] [y] = '*';

    while(!(current_field->x == 0 && current_field->y == 0)) {
        path_length += current_field->get_heatloss();
        Direction dir = current_field->get_direction();
        Direction backward_dir = get_opposite_direction(dir);
        auto backward = get_neighbor(*current_field, backward_dir);
        if (!backward) {
            current_field = NULL;
            break;
        }

        current_field = backward.value();
        map[current_field->x][current_field->y] = get_char_to_direction(dir);
    }

    if(current_field) {
        map[current_field->x][current_field->y] = '*';
    }

    for (auto &s : map) {
        std::cout << s;
    }

    std::cout << "Path length:" << path_length << std::endl;
}

void day17::Map::print_heatloss() {
    for (int x=0; x < size_x; ++x) {
        for (int y=0; y < size_y; ++y) {
            std::cout << map[x][y]->get_heatloss();
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void day17::Map::print_visited() {
    std::cout << "\033[2J\033[1;1H";
    for (int x=0; x < size_x; ++x) {
        for (int y=0; y < size_y; ++y) {
            std::cout << "   ";
        }
        std::cout << std::endl;
        for (int y=0; y < size_y; ++y) {
            auto f = map[x][y];
            //if (f->is_visisted()) {
            if (f->get_shortest_distance() < 1000) {
                auto d = f->get_shortest_distance();
                if (d < 10) {
                    std::cout << " " << f->get_shortest_distance() << " ";
                }
                else if (d < 100) {
                    std::cout << f->get_shortest_distance() << " ";
                }
                else {
                    std::cout << f->get_shortest_distance();
                }
            }
            else {
                std::cout << " * ";
            }

        }
        std::cout << std::endl;
        for (int y=0; y < size_y; ++y) {
            std::cout << "   ";
        }
        std::cout << std::endl;
    }
    usleep(10000);
}
*/
/*
void day17::Map::print_visited() {
    std::cout << "\033[2J\033[1;1H";
    for (int x=0; x < size_x; ++x) {
        for (int y=0; y < size_y; ++y) {
            auto f = map[x][y];
            if (f->is_visisted()) {
                switch(f->get_direction()){
                    case Direction::East:
                        std::cout << ">";
                        break;
                    case Direction::North:
                        std::cout << "^";
                        break;
                    case Direction::West:
                        std::cout << "<";
                        break;
                    case Direction::South:
                        std::cout << "v";
                        break;
                    case Direction::None:
                        std::cout << " ";
                }
            }
            else {
                std::cout << f->get_heatloss();
            }

        }
        std::cout << std::endl;
    }
    usleep(10000);
}
*/
