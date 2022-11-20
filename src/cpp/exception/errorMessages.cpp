#include <string>

namespace error {
    std::string keywordNotFound(std::string keyword) {
        return "Invalid Keyword: \'" + keyword + "\'";
    }

    std::string variableAlreadyExists(std::string name) {
        return "Variable \'" + name + "\' already exists!";
    }

    std::string noVarDeclaration() {
        return "No declaration for variable!";
    }

    std::string noVarName() {
        return "No name for variable!";
    }
}
