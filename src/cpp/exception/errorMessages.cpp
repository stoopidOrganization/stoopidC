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

    std::string invalidValue(std::string value) {
        return "Invalid value: \'" + value + "\'";
    }

    std::string booleanError(std::string boolean) {
        return "Error while resolving boolean: " + boolean;
    }

    std::string variableNotFound(std::string name) {
        return "Variable \'" + name + "\' doesn't exists!";
    }

    std::string stringError(std::string str) {
        return "Error while resolving string: \'" + str + "\'";
    }
}
