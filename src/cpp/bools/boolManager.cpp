#include <string>
#include <iostream>
#include <vector>

#include "../utils/utils.hpp"
#include "../math/math.hpp" 

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

    for (size_t i = 0; i < splitUp.size(); i++) {
        std::string current = splitUp[i];

        if (current == "<<") {
            if (isNumber(splitUp[i - 1]) && isNumber(splitUp[i + 1])) {
                double num1 = stod(splitUp[i - 1]);
                double num2 = stod(splitUp[i + 1]);

                if (num1 < num2) {
                    std::cout << "true" << std::endl;
                } else {
                    std::cout << "false" << std::endl;
                }
            } else {
                throw 69;
            }
        }
    }

    return "true";
}