#include <string>
#include <vector>
#include <iostream>
#include "utils.hpp"

std::string removeQuotation(std::string input) {
    std::string output;

    if (input[0] == '\"' && input[input.size() - 1]) {
        for (size_t i = 0; i < input.size(); i++) {
            if (i > 0 && i < input.size() - 1 ) {
                output += input[i];
            }
        }
    } else {
        return input;
    }

    return output;
}

std::string makeStpdString(std::string input) {
    std::vector<std::string> splitUp = splitString(input, '+');
    std::vector<std::string> trimStr;
    std::string output = "\"";

    for (size_t i = 0; i < splitUp.size(); i++) {
        trimStr.push_back(trim(splitUp[i], ' '));
    }

    for (size_t i = 0; i < trimStr.size(); i++) {
        if (trimStr[i][0] == '\"' && trimStr[i][trimStr.size() - 1]) {
            output += removeQuotation(trimStr[i]);
        } else if (isVariable(trimStr[i])) {
            output += removeQuotation(getVariable(trimStr[i]).value);
        } else {
            throw 69;
        }
    }
    
    output += '\"';

    return output;
}
