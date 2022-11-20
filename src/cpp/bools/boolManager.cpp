#include <string>
#include <vector>
#include <iostream>

#include "../utils/utils.hpp"
#include "../math/math.hpp" 
#include "../strings/stringHandler.hpp"
#include "../../c/cBools/cBools.h"
#include "../exception/errorMessages.hpp"

std::vector<std::string> splitBool(std::string input) {
    std::vector<std::string> output;
    std::string cache = "";

    for (size_t i = 0; i < input.size(); i++) {
        char current = input[i];

        if (current == '<' && input[i + 1] == '<' && cache != "") {
            output.push_back(getValue(cache));
            cache = "";
            i++;
            output.push_back("<<");
        } else if (current == '>' && input[i + 1] == '>' && cache != "") {
            output.push_back(getValue(cache));
            cache = "";
            i++;
            output.push_back(">>");
        } else if (current == '<' && input[i + 1] == '=' && cache != "") {
            output.push_back(getValue(cache));
            cache = "";
            i++;
            output.push_back("<=");
        } else if (current == '>' && input[i + 1] == '=' && cache != "") {
            output.push_back(getValue(cache));
            cache = "";
            i++;
            output.push_back(">=");
        } else if (current == '=' && input[i + 1] == '=' && cache != "") {
            output.push_back(getValue(cache));
            cache = "";
            i++;
            output.push_back("==");
        } else if (current == '!' && input[i + 1] == '=' && cache != "") {
            output.push_back(getValue(cache));
            cache = "";
            i++;
            output.push_back("!=");
        } else if (current == '&' && input[i + 1] == '&' && cache != "") {
            output.push_back(getValue(cache));
            cache = "";
            i++;
            output.push_back("&&");
        } else if (current == '|' && input[i + 1] == '|' && cache != "") {
            output.push_back(getValue(cache));
            cache = "";
            i++;
            output.push_back("||");
        } else {
            cache += current;
        }
    }

    if (output.size() == 0) {
        throw error::booleanError(cache);
    }

    output.push_back(getValue(cache));
    
    return output;
}

std::string solveBool(std::string input) {
    std::vector<std::string> splitUp = splitBool(input);
    std::vector<std::string> resolved;
    std::string result = "false";

    for (size_t i = 0; i < splitUp.size(); i++) {
        std::string current = splitUp[i];

        if (isComparator(current.c_str())) {
            if (isNumber(splitUp[i - 1]) && isNumber(splitUp[i + 1])) {
                double num1 = stod(splitUp[i - 1]);
                double num2 = stod(splitUp[i + 1]);

                resolved.push_back(std::to_string(solveDoubleBool(num1, current.c_str(), num2)));
            } else if (isString(splitUp[i - 1]) && isString(splitUp[i + 1])) {
                std::string str1 = splitUp[i - 1];
                std::string str2 = splitUp[i + 1];

                resolved.push_back(std::to_string(solveStringBool(str1.c_str(), current.c_str(), str2.c_str())));
            } else {
                throw error::booleanError(current);
            }
        } else if (isCombiner(current.c_str())) {
            resolved.push_back(current);
        } else if (current == "true" || current == "false") {
            resolved.push_back(std::to_string(strToBool(current.c_str())));
        }
    }

    int cache[2];
    cache[0] = -1;
    cache[1] = -1;

    for (size_t i = 0; i < resolved.size(); i++) {
        if (isBool(resolved[i].c_str()) && cache[0] == -1) {
            cache[0] = strToBool(resolved[i].c_str());
        } else if (isCombiner(resolved[i].c_str()) && isBool(resolved[i + 1].c_str())) {
            cache[1] = strToBool(resolved[i + 1].c_str());

            cache[0] = solveCombiner(cache[0], resolved[i].c_str(), cache[1]);

            i++;
        } else {
            throw error::booleanError(resolved[i]);
        }
    }

    if (cache[0] == 0) {
        result = "false";
    } else if (cache[0] == 1) {
        result = "true";
    } else {
        throw error::booleanError(std::to_string(cache[0]));
    }
    
    return result;
}