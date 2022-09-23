#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

double mathModulo(double num1, double num2) {
    return (num1 - (num2 * (int)(num1 / num2)));
}

double mathPower(double num1, int num2) {
    double result = 1;

    for(int i = 0; i < num2; i++) {
        result *= num1;
    }

    return result;
}

bool isOperator(char op) {
    if(op == '+' || op == '-' || op == '*' || op == '/' || op == '%' || op == '^') {
        return true;
    }

    return false;
}

double solveSimpleEquasion(double num1, char operator ,double num2) {
    if(operator == '+') {
        return num1 + num2;
    } else if(operator == '-') {
        return num1 - num2;
    } else if(operator == '*') {
        return num1 * num2;
    } else if(operator == '/') {
        return num1 / num2;
    } else if(operator == '%') {
        return mathModulo(num1, num2);
    } else if(operator == '^') {
        return mathPower(num1, num2);
    }

    return 0;
}

double solveComplexEquasion(char* equasion) {
    char* finishedEquasion = equasion;
    int numLimit = 1024;

    // resolve stage 1 operation
    for(int i = 0; i < getSize(equasion); i++) {
        if(finishedEquasion[i] == '^') {
            // get first number
            int num1Start = 0;
            for(int j = i - 1; j >= 0; j--) {
                if(isOperator(equasion[j])) {
                    num1Start = j + 1;
                }
            }
            
            char* num1AsStr = malloc(numLimit * sizeof(char));
            int k = 0;
            for(int j = num1Start; j < i; j++) {
                num1AsStr[k] = equasion[j];
            }
            num1AsStr[k + 1] = '\0';

            double num1 = strToDouble(num1AsStr);

            free(num1AsStr);

            // get second number
            char* num2AsStr = malloc(numLimit * sizeof(char));
            k = 0;
            for(int j = i + 1; j < getSize(equasion); j++) {
                if(isOperator(equasion[j])) {
                    break;
                }

                num2AsStr[k] = equasion[j];
            }
            num2AsStr[k + 1] = '\0';
            
            double num2 = strToDouble(num2AsStr);

            free(num2AsStr);

            double result = solveSimpleEquasion(num1, '^', num2);

            printf("%f\n", result);
        }
    }

    return 0.0;
}