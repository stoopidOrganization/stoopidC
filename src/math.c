#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"

double mathModulo(double num1, double num2) {
    return (num1 - (num2 * (int)(num1 / num2)));
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
        return pow(num1, num2);
    }

    return 0;
}

char* solveComplexEquasion(char* equasion) {
    char* finishedEquasion = equasion;
    int numLimit = 1024;

    // resolve stage 1 operation
    for(int i = 0; i < getSize(equasion); i++) {
        if(isOperator(finishedEquasion[i])) {
            // get first number
            int num1Start = 0;
            for(int j = i - 1; j >= -1; j--) {
                if(isOperator(finishedEquasion[j])) {
                    num1Start = j + 1;
                }
            }
            char* num1AsStr = malloc(numLimit * sizeof(char));
            int k = 0;
            for(int j = num1Start; j < i; j++) {
                num1AsStr[k] = finishedEquasion[j];
                k++;
            }
            num1AsStr[k] = '\0';

            double num1 = strToDouble(num1AsStr);

            free(num1AsStr);

            // get second number
            int end;
            char* num2AsStr = malloc(numLimit * sizeof(char));
            k = 0;
            for(int j = i + 1; j < getSize(finishedEquasion); j++) {
                if(isOperator(finishedEquasion[j]) || finishedEquasion[j] == '\0') {
                    end = j;
                    break;
                }

                num2AsStr[k] = finishedEquasion[j];
            }
            num2AsStr[k + 1] = '\0';
            
            double num2 = strToDouble(num2AsStr);

            free(num2AsStr);

            char* result = malloc(numLimit);
            
            if(finishedEquasion[i] == '^') {
                sprintf(result, "%f", solveSimpleEquasion(num1, '^', num2));
            }
            
            finishedEquasion = replaceString(equasion, result, 0, end);

            return solveComplexEquasion(finishedEquasion);
        }
    }

    return finishedEquasion;
}
