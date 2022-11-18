#include <iostream>
#include <string>

#include "../../main.hpp"

void throwException(std::string msg) {
    std::string output = "The Interpreter crashed in line ";
    output += std::to_string(getCurrentLine() + 1);
    output += ":\n\t";
    output += msg;

    std::cerr << output << std::endl;
}