#include <string>
#include <vector>
#include <iostream>

#include "../utils/utils.hpp"
#include "../exception/errorMessages.hpp"

bool isString(std::string str) {
    if (str[0] == '\"' && str[str.size() - 1] == '\"') return 1;

    return 0;
}

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

bool validateString(std::string str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (i > 0) {

        }
        if (str[i] == '\"') {
            if (i > 0) {
                if (str[i - 1] != '\\') {
                    return false;
                }
            } else {
                return false;
            }
        }
    }

    return true;
}

std::string makeStpdString(std::string input) {
    std::vector<std::string> splitUp = utils::splitString(input, '+');
    std::vector<std::string> trimStr;
    std::string output = "\"";

    for (size_t i = 0; i < splitUp.size(); i++) {
        if (!validateString(splitUp[i])) throw error::stringError(splitUp[i]);

        trimStr.push_back(utils::trim(splitUp[i], ' '));
    }

    for (size_t i = 0; i < trimStr.size(); i++) {
        if (trimStr[i][0] == '\"' && trimStr[i][trimStr[i].size() - 1] == '\"') {
            output += removeQuotation(trimStr[i]);
        } else if (isVariable(trimStr[i])) {
            output += removeQuotation(getVariable(trimStr[i]).value);
        } else {
            throw error::stringError(trimStr[i]);
        }
    }
    
    output += '\"';

    return output;
}
