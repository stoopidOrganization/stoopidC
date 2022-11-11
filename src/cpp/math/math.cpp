#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <stack>

#include "../../c/cMath/cMath.h"
#include "../variables/variableManager.hpp"

int isNumber(std::string num) {
    for (size_t i = 0; i < num.size(); i++) {
        if (!isCharNum(num[i])) {
            return 0;
        }
    }

    return 1;
}

std::vector<std::string> splitEquasion(std::string equasion) {
    std::string cache = "";
    std::string opBuffer = "";
    std::vector<std::string> equasionAsList;

    for (size_t i = 0; i < equasion.size(); i++) {
        // if operator is actually part of a negative number then add it to the cache
        if (isOperator(equasion[i]) || equasion[i] == '(' || equasion[i] == ')') {
            if (i == 0) {
                cache += equasion[i];
                continue;
            } else if (isOperator(equasion[i - 1])) {
                cache += equasion[i];
                continue;
            }

            // if the cache isnt empty and an operator is found, add it to the result
            if (cache != "") {
                if (isVariable(cache) && isNumber(getVariable(cache).value)) {
                    equasionAsList.push_back(getVariable(cache).value);
                    cache = "";
                } else if (isNumber(cache)) {
                    equasionAsList.push_back(cache);
                    cache = "";
                } else {
                    throw 69;
                }
            }

            // add operators and brackets to the list
            if (isOperator(equasion[i])) {
                opBuffer += equasion[i];
                equasionAsList.push_back(opBuffer);
                opBuffer = "";
            } else if (equasion[i] == '(') {
                equasionAsList.push_back("(");
            } else if (equasion[i] == ')') {
                equasionAsList.push_back(")");
            }
        } else {
            cache += equasion[i];
        }
    }

    if (isVariable(cache) && isNumber(getVariable(cache).value)) {
        equasionAsList.push_back(getVariable(cache).value);
        cache = "";
    } else if (isNumber(cache)) {
        equasionAsList.push_back(cache);
        cache = "";
    } else {
        throw 69;
    }

    return equasionAsList;
}

std::queue<std::string> convertToRPN(std::vector<std::string> equasion) {
    std::queue<std::string> equasionInRPN;

    std::vector<std::stack<std::string>> operators;
    std::stack<std::string> helpStack;
    operators.push_back(helpStack);

    int currentStack = 0;

    for (size_t i = 0; i < equasion.size(); i++) {
        std::string current = equasion[i];

        if (isNumber(current)) {
            equasionInRPN.push(current);
        } else if (isOperator(current[0]) && operators[currentStack].empty()) {
            operators[currentStack].push(current);
        } else if (isOperator(current[0] && calcOperatorScore(current[0]) >= calcOperatorScore(operators[currentStack].top()[0]))) {
            operators[currentStack].push(current);
        } else if (current[0] == '(') {
            currentStack++;
            operators.push_back(helpStack);
        } else if (current[0] == ')') {
            while (operators[currentStack].empty()) {
                equasionInRPN.push(operators[currentStack].top());
                operators[currentStack].pop();
            }

            currentStack--;
        } else {
            while (operators[currentStack].empty()) {
                if (calcOperatorScore(current[0]) < calcOperatorScore(operators[currentStack].top()[0])) {
                    equasionInRPN.push(operators[currentStack].top());
                    operators[currentStack].pop();
                } else {
                    break;
                }
            }

            operators[currentStack].push(current);
        }
    }

    while (currentStack >= 0) {
        while (!operators[currentStack].empty()) {
            equasionInRPN.push(operators[currentStack].top());

            operators[currentStack].pop();
        }

        currentStack--;
    }

    return equasionInRPN;
}

double solveEquasion(std::string equasion) {
    std::queue<std::string> equasionInRPN = convertToRPN(splitEquasion(equasion));
    std::stack<std::string> storage;

    while (!equasionInRPN.empty()) {
        std::string current = equasionInRPN.front();
        equasionInRPN.pop();

        if (isOperator(current[0])) {
            std::string num2Str = storage.top();
            double num2 = std::stod(num2Str);
            storage.pop();
            std::string num1Str = storage.top();
            double num1 = std::stod(num1Str);
            storage.pop();

            storage.push(std::to_string(solveSimpleEquasion(num1, current[0], num2)));
        } else {
            storage.push(current);
        }
    }

    return std::stod(storage.top());
}