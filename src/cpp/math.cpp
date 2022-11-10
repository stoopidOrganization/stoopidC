#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include "../c/cMath.h"

std::vector<std::string> splitEquasion(std::string equasion) {
    std::string cache = "";
    std::vector<std::string> equasionAsList;

    for (size_t i = 0; i < equasion.size(); i++) {
        // if operator is actually part of a negative number then add it to the cache
        if (isOperator(equasion[i]) || equasion[i] == '(' || equasion[i] == ')') {
            if (i == 0) {
                cache += equasion[i];
                continue;
            } else if (isOperator(equasion[i - 1])) {
                cache += equasion[i];
                continue;
            }
        }
    }

    return equasionAsList;
}

std::queue<std::string> convertToRPN(std::vector<std::string> equasion) {
    std::queue<std::string> output;

    return output;
}

double solveEquasion(std::string equasion) {
    // std::queue<std::string> equasionInRPN = convertToRPN(splitEquasion(equasion));

    std::vector<std::string> splitUp = splitEquasion(equasion);

    for (size_t i = 0; i < splitUp.size(); i++) {
        std::string current = splitUp[i];

        std::cout << current << std::endl;
    }

    return 0.1;
}