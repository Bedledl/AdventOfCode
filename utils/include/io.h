#ifndef IO_H
#define IO_H

#include <filesystem>
#include <string>
#include <vector>

class Input {
    public:
    std::string puzzle_name;
    Input() = delete;
    Input(std::string puzzle_name) : puzzle_name(puzzle_name) {};
    virtual ~Input() = default;

    void init_from_file(std::filesystem::path path);
    void init_from_stream(std::istream &input);
    private:
    // we can pass lines by value, but better use an rvalue:)
    virtual void set_content(std::vector<std::string> lines) = 0;

//    protected:
    //https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c67-a-polymorphic-class-should-suppress-public-copymove
//    Input(const Input&) = delete;
//    Input& operator=(const Input&) = delete;
};

struct Output {
    Output();
    virtual void to_file();
    virtual void to_terminal();
};

#endif
