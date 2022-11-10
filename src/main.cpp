#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "utils.hpp"

int main() {
    // load file
    std::ifstream Script("test.stpd");

    std::vector<std::string> lines;

    std::string cache;

    while (getline (Script, cache)) {
        lines.push_back(removeSpace(cache));
    }

    Script.close();

    // output file
    for (size_t i = 0; i < lines.size(); i++) {
        std::cout << lines[i] << std::endl;
    }

    return 0;
}