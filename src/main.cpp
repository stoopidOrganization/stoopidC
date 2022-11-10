#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "cpp/utils.hpp"

int main() {
    // load file
    std::ifstream Script("test.stpd");

    std::vector<std::string> lines;

    std::string cache;

    while (getline (Script, cache)) {
        lines.push_back(removeSpace(cache));
    }

    Script.close();

    // output file
    for (size_t i = 0; i < lines.size(); i++) {
        std::vector<std::string> linepieces = splitString(lines[i], ':');

        if (linepieces[0] == "var") {
            std::vector<std::string> varPieces = splitString(linepieces[1], '=');

            Variable newVar;
            newVar.name = varPieces[0];
            newVar.value = varPieces[1];

            addVariable(newVar);
        } else if (linepieces[0] == "out") {
            std::cout << getValue(linepieces[1]) << std::endl;
        }
    }

    std::cout << solveEquasion("1+1+1") << std::endl;

    return 0;
}