#include <string>
#include <queue>
#include <vector>
#include <iostream>

std::vector<std::string> splitEquasion(std::string equasion) {
    std::vector<std::string> output;

    output.push_back("test");

    return output;
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