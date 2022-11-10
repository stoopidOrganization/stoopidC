#include <iostream>
#include <fstream>
#include <vector>

std::string removeSpace(std::string input) {
    std::string output = "";

    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] != ' ') {
            output += input[i];
        }
    }

    return output;
}

int main() {
    // load file
    std::ifstream Script("test.stpd");

    std::vector<std::string> lines;

    std::string cache;

    while (getline (Script, cache)) {
        lines.push_back(cache);
    }

    Script.close();

    // output file
    for (size_t i = 0; i < lines.size(); i++) {
        std::cout << removeSpace(lines[i]) << std::endl;
    }

    return 0;
}