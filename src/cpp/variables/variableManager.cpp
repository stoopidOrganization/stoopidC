#include <vector>
#include <string>
#include <iostream>

#include "../utils/utils.hpp"

std::vector<Variable> variables;

std::vector<Variable> getVariables() {
    return variables;
}

int addVariable(Variable var) {
    for (size_t i = 0; i < variables.size(); i++) {
        if (var.name == variables[i].name) {
            std::string error = "Variable \'" + var.name + "\' already exists!";
            throw error;
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
    bool str = false;
    bool found = false;

    for (size_t i = 0; i < input.size(); i++) {
        if (str) {
            value += input[i];
        } else {
            if (input[i] == '=') {
                str = true;
                found = true;
                continue;
            }
            
            name += input[i];
        }
    }

    if (!found) {
        std::string error = "No declaration for variable!";
        throw error;
    }

    name = trim(name, ' ');

    if (name.size() == 0) {
        std::string error = "No name for variable!";
        throw error;
    }

    output.push_back(name);
    output.push_back(value);

    return output;
}

int setVariable(std::string name, std::string value) {
    if (!isVariable(name)) {
        throw 69;
        return 1;
    }

    for (size_t i = 0; i < variables.size(); i++) {
        if (variables[i].name == name) {
            variables[i].value = value;
        }
    }
    

    return 0;
}