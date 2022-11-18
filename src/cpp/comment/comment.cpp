#include <string>

#include "../utils/utils.hpp"

std::string removeComment(std::string input) {
    std::string output = "";

    for (size_t i = 0; i < input.size(); i++) {
        char current = input[i];

        if (current != '#') {
            output += current;
        } else {
            break;
        }
    }

    return trim(output, ' ');
}