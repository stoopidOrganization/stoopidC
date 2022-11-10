#include <string>
#include <vector>
#include "variableManager.hpp"

std::string removeSpace(std::string input) {
    std::string output = "";

    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] != ' ') {
            output += input[i];
        }
    }

    return output;
}

std::vector<std::string> splitString(std::string input, char splitter) {
    std::vector<std::string> output;
    std::string cache = "";

    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] == splitter) {
            output.push_back(cache);
            cache = "";
            continue;
        } else {
            cache += input[i];
            continue;
        }
    }

    output.push_back(cache);
    cache = "";

    return output;
}

std::string getValue(std::string input) {
    for (size_t i = 0; i < getVariables().size(); i++) {
        Variable current = getVariables()[i];

        if (input == current.name) {
            return current.value;
        }
    }

    return input;
}