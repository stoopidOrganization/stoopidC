#include <string>
#include <iostream>
#include <vector>

#include "../utils/utils.hpp"
#include "../math/math.hpp" 
#include "../strings/stringHandler.hpp"
#include "../../c/cBools/cBools.h"

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

    output.push_back(getValue(cache));
    
    return output;
}

std::string solveBool(std::string input) {
    std::vector<std::string> splitUp = splitBool(input);
    std::vector<std::string> resolved;

    for (size_t i = 0; i < splitUp.size(); i++) {
        std::string current = splitUp[i];

        if (isComparator(current.c_str())) {
            if (isNumber(splitUp[i - 1]) && isNumber(splitUp[i + 1])) {
                double num1 = stod(splitUp[i - 1]);
                double num2 = stod(splitUp[i + 1]);

                resolved.push_back(std::to_string(solveDoubleBool(num1, current.c_str(), num2)));
            }
        } else if (isCombiner(current.c_str())) {
            
        }
    }

    return "true";
}