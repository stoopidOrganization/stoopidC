#include <string>
#include <vector>

#include "../math/math.hpp"
#include "../variables/variableManager.hpp"

std::string removeChar(std::string input, char remove);

std::vector<std::string> splitString(std::string input, char splitter);

std::string getValue(std::string input);

std::string trim(std::string input, char trimmer);