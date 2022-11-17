#include <string>
#include <vector>
#include <iostream>

#include "../variables/variableManager.hpp"
#include "../math/math.hpp"
#include "../strings/stringHandler.hpp"
#include "../bools/boolManager.hpp"
#include "../../c/cBools/cBools.h"

std::string removeChar(std::string input, char remove) {
    std::string output = "";

    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] != remove) {
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


std::string trim(std::string input, char trimmer) {
    size_t start = 0;
    size_t end = input.size();
    std::string output = "";

    for (size_t i = 0; i < input.size(); i++) {
        if (input[i] != trimmer) {
            start = i;
            break;
        }
    }

    for (size_t i = input.size() - 1; i >= 0; i--) {
        if (input[i] != trimmer) {
            end = i + 1;
            break;
        }
    }

    for (size_t i = start; i < end; i++) {
        output += input[i];
    }

    return output;
}

std::string getValue(std::string input) {
    try {
        return std::to_string(solveEquasion(removeChar(input, ' ')));
    } catch (int mathErr) {
        try {
            return makeStpdString(input);
        } catch (int strErr) {
            if (isVariable(trim(input, ' '))) {
                return getVariable(input).value;
            }

            if (isBool(trim(input, ' ').c_str())) {
                return trim(input, ' ');
            }

            try {
                return solveBool(trim(input, ' '));
            } catch (int boolErr) {
                throw 69;
            }
        }
    }

    return input;
}