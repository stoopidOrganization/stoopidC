#include <iostream>
#include <string>

#include "../../main.hpp"

void throwException(std::string msg) {
    std::cout << "\n-----------------------------------\n" << std::endl;

    std::string output = "The Interpreter crashed in line ";
    output += std::to_string(getCurrentLine() + 1);
    output += ":\n\t";
    output += msg;

    std::cerr << output << std::endl;

    std::cout << "\n-----------------------------------\n" << std::endl;
}