#include <string>
#include <fstream>
#include <sstream>

#include <iostream>

#include <vector>

#include "include/io.h"

void Input::init_from_file(std::filesystem::path path) {
    std::ifstream file;
    file.open(path);

    if(file.fail()) {
        throw std::runtime_error("File cound not be opened: " + std::string(path));
    }

    std::vector<std::string> lines;

    std::string line;
    while (std::getline(file, line)) {
        lines.emplace_back(std::move(line));
    }

    // Errors here should terminate the program
    this->set_content(lines);
};

void Input::init_from_stream(std::istream &input) {
    int line_count;
    std::string line;
    std::vector<std::string> lines;

    std::cout << "Here, you can put some input for puzzle " << this->puzzle_name << std::endl;
    std::cout << "Please put in how many lines the input will have: " << std::endl;

    std::getline(input, line);
    line_count = std::stoi(line);

    for (int i = 0; i < line_count; i++) {
        std::getline(input, line);
        lines.emplace_back(std::move(line));
    }

    this->set_content(lines);
};
