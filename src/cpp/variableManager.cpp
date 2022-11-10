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