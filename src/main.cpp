#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "utils.hpp"

int main() {
    // load file
    std::ifstream Script("test.stpd");

    std::vector<std::string> lines;

    std::string cache;

    while (getline (Script, cache)) {
        lines.push_back(removeSpace(cache));
    }

    Script.close();

    std::vector<Variable> variables;

    // output file
    for (size_t i = 0; i < lines.size(); i++) {
        std::vector<std::string> linepieces = splitString(lines[i], ':');

        if (linepieces[0] == "var") {
            std::vector<std::string> varPieces = splitString(linepieces[1], '=');

            Variable newVar;
            newVar.name = varPieces[0];
            newVar.value = varPieces[1];

            variables.push_back(newVar);
        } else if (linepieces[0] == "out") {
            std::cout << getValue(linepieces[1], variables) << std::endl;
        }
    }

    return 0;
}