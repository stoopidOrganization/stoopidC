#include <vector>
#include <string>
#include "variable.hpp"

std::vector<Variable> getVariables();

int addVariable(Variable var);

Variable getVariable(std::string name);

int isVariable(std::string name);

std::vector<std::string> getVarPieces(std::string input);