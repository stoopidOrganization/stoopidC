#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "cpp/utils/utils.hpp"
#include "cpp/strings/stringHandler.hpp"
#include "cpp/bools/boolManager.hpp"
#include "cpp/comment/comment.hpp"
#include "cpp/exception/exceptionHandler.hpp"
#include "cpp/exception/errorMessages.hpp"

size_t line = 0;

size_t getCurrentLine() {
    return line;
}

void setCurrentLine(size_t number) {
    line = number;
}

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
    for (line = 0; line < lines.size(); line++) {
        try {
            std::vector<std::string> linepieces = splitString(removeComment(lines[line]), ':');
            linepieces[0] = removeChar(linepieces[0], ' ');

            if (linepieces[0] == "var") {
                // initialize a new variable
                std::vector<std::string> varPieces = getVarPieces(combineArgs(linepieces, 1));

                Variable newVar;
                newVar.name = removeChar(varPieces[0], ' ');
                newVar.value = getValue(trim(varPieces[1], ' '));

                addVariable(newVar);
            } else if (linepieces[0] == "out") {
                // print something to the output
                std::cout << removeQuotation(getValue(combineArgs(linepieces, 1))) << std::endl;
            } else if (linepieces[0] == "goto") {
                // change the next line read by the interpreter
                line = stoi(linepieces[1]) - 2;
            } else if (linepieces[0] == "" || linepieces[0][0] == '#') {
                // do nothing on empty lines pr comments
                continue;
            } else {
                std::vector<std::string> varPieces;

                try {
                    varPieces = getVarPieces(combineArgs(linepieces, 0));
                } catch (std::string varErr) {
                    throw error::keywordNotFound(linepieces[0]);
                    return 1;
                }

                
                if (isVariable(varPieces[0])) {
                    setVariable(varPieces[0], getValue(trim(varPieces[1], ' ')));
                } else {
                    throw error::variableNotFound(varPieces[0]);
                }
            }
        } catch (std::string error) {
            throwException(error);
            return 1;
        }
    }

    return 0;
}