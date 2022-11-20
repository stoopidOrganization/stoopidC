namespace error {
    // variable errors
    std::string variableNotFound(std::string name);
    std::string variableAlreadyExists(std::string name);
    std::string noVarDeclaration();
    std::string noVarName();

    // value errors
    std::string keywordNotFound(std::string keyword);
    std::string invalidValue(std::string value);
    std::string booleanError(std::string boolean);
    std::string stringError(std::string str);
    std::string mathError(std::string math);
    std::string escapeError(char ch);
}
