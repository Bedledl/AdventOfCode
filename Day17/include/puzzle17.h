#include <string>
#include <regex>
#include <set>
#include <optional>
#include <functional>

#include "io.h"
#include "puzzle.h"
#include "direction.h"

namespace day17
{
    /// @brief Stores the current end field, length and moves in the current direction for a Path.
    /// At each node a copy of the respective is made for each available direction.
    class Path {
        private:
        int min_distance = 0;
        Direction current_direction = Direction::None;
        int moved_in_dir = 0;
        int x;
        int y;
        public:
        Path(int x, int y) : x(x), y(y) {};
        std::pair<int, int> get_coordinates() {return {x, y};}
        void move(Direction dir, int additional_heatloss);
        // this method is important to sort the Paths in the Queue.
        // It is independent of the coordinates of the path.
        bool is_smaller_than(Path &path);
        bool keeps_x_blocks_rule(Direction dir, int x) {
            if (dir != current_direction) {
                return true;
            }
            return moved_in_dir < x;
        }
        bool keeps_at_least_x_blocks_rule(Direction dir, int x) {
            if (dir != current_direction) {
                if(moved_in_dir < x) {
                    return false;
                }
            }
            return true;
        }
        bool is_opposite_direction(Direction dir) {
            auto opposite = get_opposite_direction(current_direction);
            if(!opposite) {
                return false;
            }
            return dir == opposite.value();
        }
        const int get_shortest_distance() {return min_distance;};
        Direction get_direction() { return current_direction; }
        int get_moved_in_dir() { return moved_in_dir;};
    };

    class Field {
    public:
        Field(int x, int y, int heatloss, int max_same_dir);
        const int get_heatloss() {return heatloss;}
        std::pair<int, int> get_coordinates() {
            return {x, y};
        }
        // update hiscores in dir_to_pa
        bool update_highscores(Direction dir, int moved_in_dir, int distance_until_now);
        void make_start();
        int get_shortest_distance();
    private:
        const int x;
        const int y;
        const int heatloss;
        const int max_same_dir;
        // tthe highscores variable helps with path elimination. The decision about path elimination is implement in update_highscores
        // contains the shortes distance to this specific field comming from each direction and for each numbers of moves in direction made
        std::map<Direction, std::vector<int>> highscores;
    };

    class PathComparator {
        public:
        bool operator()(Path *one, Path* two) const {
            return one->is_smaller_than(*two);
        }
    };

    class Map {
        public:
        int size_x, size_y;
        /// @brief
        /// @param  should be an i x j vector
        Map(std::vector<std::vector<int>> raw_map, int max_same_dir);
        Field* get_at(int x, int y);
        Field* get_neighbor(day17::Field &field, Direction dir, int n = 1);
        Field* get_neighbor(int x, int y, Direction dir, int n = 1);
        /// @brief Prints the path to the specified destination
        /// @param x
        /// @param y
        private:
            std::vector<std::vector<Field>> map;

    };



    template <typename T, typename TComp>
    class DijkstraQueue {
        std::set<T*, TComp> queue;
    public:
        // has no knowledge over how paths are updated
        // inserts elements new, if they aren't newly generated
        void update(T* path, bool new_element) {
            if(!new_element) {
                queue.erase(path);
            }
            queue.insert(path);

        }
        T* pop() {
            auto first = *(queue.begin());
            queue.erase(first);
            return first;
        }

        void print(std::function<void(T&)> print_func) {
            for (auto &i : queue) {
                print_func(*i);
            }
            std::cout << "\n";
        }

        bool empty() { return queue.empty(); }
    };


    /// @brief Pathfinder strategy for Puzzle 17
    class ShortestDistanceFinder {
        const int min_same_dir;
        const int max_same_dir;
        public:
        ShortestDistanceFinder(int min_same_dir, int max_same_dir) : min_same_dir(min_same_dir), max_same_dir(max_same_dir) {};
        int find_shortest_path(Map &map, int startx, int starty, int endx, int endy);
    };

    struct Input17 : Input
    {
        std::unique_ptr<Map> map;

    private:
    const int max_same_dir;
        void set_content(std::vector<std::string> lines) override;

    public:
        using Input::Input;
        Input17(std::string name, int max_same_dir) : Input(name), max_same_dir(max_same_dir) {};
    };

    class Puzzle17 : Puzzle<Input17>
    {
    public:
        Puzzle17() : Puzzle<Input17>("17"){};

        /// @brief Run the first part of day 17's puzzle.
        /// @param input TODO
        /// @return
        int run_part_1(Input17 &input) override;

        /// @brief Run the second part of the day 17's puzzle
        /// @param input
        /// @return
        int run_part_2(Input17 &input) override;
    };
}
