#ifndef IO_H
#define IO_H

#include <filesystem>
#include <string>
#include <vector>



/// @brief Base class for puzzle inputs storing the input data
///
/// This is the base class for puzzle inputs. For each puzzle create an individual subclass
/// that can then contain specialised attributes containing the input data.
///
class Input {
    public:
    /// @brief Name of the Puzzle for which this input object is created.
    std::string puzzle_name;
    Input() = delete; // not necessary, changes error message
    Input(std::string puzzle_name) : puzzle_name(puzzle_name) {};
    virtual ~Input() = default;

    /// @brief Fills this input with data from the file ´path´
    /// @param path Path to the file containing data
    void init_from_file(std::filesystem::path path);

    /// @brief Fills this input with data from stream
    /// @param input An input stream e.g. std::cin
    void init_from_stream(std::istream &input);
    private:

    /// @brief Called with lines containing the input data. Implements how this data is stored.
    /// @param lines raw input data e.g. lines read from file
    virtual void set_content(std::vector<std::string> lines) = 0;

//    protected:
    //https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c67-a-polymorphic-class-should-suppress-public-copymove
//    Input(const Input&) = delete;
//    Input& operator=(const Input&) = delete;
};

/// @brief Currently not used!
struct Output {
    Output();
    virtual void to_file();
    virtual void to_terminal();
};

#endif
