#include <vector>
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