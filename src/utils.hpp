#include <string>
#include <vector>
#include "variable.hpp"

std::string removeSpace(std::string input);

std::vector<std::string> splitString(std::string input, char splitter);

std::string getValue(std::string input, std::vector<Variable> variables);
