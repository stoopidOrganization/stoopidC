#include <string>

std::string removeSpace(std::string input) {
    std::string output = "";

    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] != ' ') {
            output += input[i];
        }
    }

    return output;
}