#include <string>
#include <iostream>
#include <vector>

#include "../utils/utils.hpp"

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
        std::cout << splitUp[i] << std::endl;
    }

    return "true";
}