#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "cpp/utils/utils.hpp"
#include "cpp/strings/stringHandler.hpp"
#include "cpp/bools/boolManager.hpp"

int main(int argc, char *argv[]) {
    std::vector<std::string> lines;
    std::string filename = "";

    if (argc > 1) {
        // load file
        filename = argv[1];
        std::ifstream Script(filename);
        std::string cache;

        while (getline (Script, cache)) {
            lines.push_back(cache);
        }

        Script.close();
    } else {
        std::cerr << "No filename was given!" << std::endl;
        return 1;
    }

    if (lines.size() < 1) {
        std::cerr << "The file " + filename + " doesn't exist!" << std::endl;
        return 1;
    }

    // output file
    for (size_t i = 0; i < lines.size(); i++) {
        std::vector<std::string> linepieces = splitString(lines[i], ':');
        linepieces[0] = removeChar(linepieces[0], ' ');

        if (linepieces[0] == "var") {
            std::vector<std::string> varPieces = splitString(linepieces[1], '=');

            Variable newVar;
            newVar.name = removeChar(varPieces[0], ' ');
            newVar.value = getValue(trim(varPieces[1], ' '));

            addVariable(newVar);
        } else if (linepieces[0] == "out") {
            std::cout << removeQuotation(getValue(linepieces[1])) << std::endl;
        } else if (linepieces[0] == "goto") {
            i = stoi(linepieces[1]) - 2;
        }
    }

    return 0;
}