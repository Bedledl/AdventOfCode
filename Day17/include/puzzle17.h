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
        unsigned min_distance = 0;
        uint8_t moved_in_dir = 0;
        uint8_t x;
        uint8_t y;
        Direction current_direction = Direction::None;
        public:
        Path(uint8_t x, uint8_t y) : x(x), y(y) {};
        [[nodiscard]] std::pair<uint8_t, uint8_t> get_coordinates() const {return {x, y};}
        void move(Direction dir, uint8_t additional_heatloss);
        // this method is important to sort the Paths in the Queue.
        // It is independent of the coordinates of the path.
        [[nodiscard]] bool is_smaller_than(Path &path) const;
        auto operator<=>(const Path& path) const = default;
        [[nodiscard]] bool keeps_x_blocks_rule(Direction dir, int x) const {
            if (dir != current_direction) {
                return true;
            }
            return moved_in_dir < x;
        }
        [[nodiscard]] bool keeps_at_least_x_blocks_rule(Direction dir, uint8_t x) const {
            if (dir != current_direction) {
                if(moved_in_dir < x) {
                    return false;
                }
            }
            return true;
        }
        [[nodiscard]] bool is_opposite_direction(Direction dir) const {
            auto opposite = get_opposite_direction(current_direction);
            if(!opposite) {
                return false;
            }
            return dir == opposite.value();
        }
        [[nodiscard]] unsigned get_shortest_distance() const {return min_distance;};
        [[nodiscard]] Direction get_direction() const { return current_direction; }
        [[nodiscard]] uint8_t get_moved_in_dir() const { return moved_in_dir;};
    };

    class Field {
    public:
        Field(uint8_t x, uint8_t y, uint8_t heatloss, uint8_t max_same_dir);
        [[nodiscard]] uint8_t get_heatloss() const {return heatloss;}
        [[nodiscard]] std::pair<uint8_t, uint8_t> get_coordinates() const {
            return {x, y};
        }
        // update hiscores in dir_to_pa
        bool update_highscores(Direction dir, uint8_t moved_in_dir, unsigned distance_until_now);
        void make_start();
        unsigned get_shortest_distance() const;
    private:
        const uint8_t x;
        const uint8_t y;
        const uint8_t heatloss;
        const uint8_t max_same_dir;
        // tthe highscores variable helps with path elimination. The decision about path elimination is implement in update_highscores
        // contains the shortes distance to this specific field comming from each direction and for each numbers of moves in direction made
        std::map<Direction, std::vector<unsigned>> highscores;
    };

    class PathComparator {
        public:
        [[nodiscard]] bool operator()(Path *one, Path* two) const {
            return one->is_smaller_than(*two);
        }
    };

    class Map {
        public:
        uint8_t size_x, size_y;
        /// @brief
        /// @param  should be an i x j vector
        Map(std::vector<std::vector<uint8_t>> raw_map, uint8_t max_same_dir);
        Field* get_at(uint8_t x, uint8_t y);
        Field* get_at(std::pair<uint8_t, uint8_t> coords);
        Field* get_neighbor(day17::Field &field, Direction dir, uint8_t n = 1);
        Field* get_neighbor(uint8_t x, uint8_t y, Direction dir, uint8_t n = 1);
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
    public:
        ShortestDistanceFinder(uint8_t min_same_dir, uint8_t max_same_dir) : min_same_dir(min_same_dir), max_same_dir(max_same_dir) {};
        unsigned find_shortest_path(Map &map, uint8_t startx, uint8_t starty, uint8_t endx, uint8_t endy) const;
    private:
        const uint8_t min_same_dir;
        const uint8_t max_same_dir;
        bool try_moving_path_n_steps(Map &map, Path &path, uint8_t steps, Direction dir) const;
    };

    struct Input17 : Input
    {
        std::unique_ptr<Map> map;

    private:
    const uint8_t max_same_dir;
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
