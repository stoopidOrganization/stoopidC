#include <vector>
#include <string>
#include "variable.hpp"

std::vector<Variable> variables;

std::vector<Variable> getVariables() {
    return variables;
}

int addVariable(Variable var) {
    for (size_t i = 0; i < variables.size(); i++) {
        if (var.name == variables[i].name) {
            return 1;
        }
    }

    variables.push_back(var);
    return 0;
}

Variable getVariable(std::string name) {
    for (size_t i = 0; i < variables.size(); i++) {
        if (name == variables[i].name) {
            return variables[i];
        }
    }

    Variable dummy;
    dummy.name = "NULL";
    dummy.value = "NULL";

    return dummy;
}

int isVariable(std::string name) {
    for (size_t i = 0; i < variables.size(); i++) {
        if (name == variables[i].name) {
            return 1;
        }
    }

    return 0;
}

std::vector<std::string> getVarPieces(std::string input) {
    std::vector<std::string> output;
    std::string name = "";
    std::string value = "";
    int str = 0;

    for (size_t i = 0; i < input.size(); i++) {
        if (str > 0) {
            value += input[i];
        } else {
            if (input[i] == '=') {
                str++;
                continue;
            }
            
            name += input[i];
        }
    }

    output.push_back(name);
    output.push_back(value);

    return output;
}