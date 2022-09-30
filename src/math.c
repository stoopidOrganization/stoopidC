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
            int end;
            char* num2AsStr = malloc(numLimit * sizeof(char));
            k = 0;
            for(int j = i + 1; j < getSize(equasion); j++) {
                if(isOperator(equasion[j])) {
                    end = j;
                    break;
                }

                num2AsStr[k] = equasion[j];
            }
            num2AsStr[k + 1] = '\0';
            
            double num2 = strToDouble(num2AsStr);

            free(num2AsStr);

            char* result = malloc(numLimit);
            sprintf(result, "%f", solveSimpleEquasion(num1, '^', num2));

            printf("result: %s\n", result);

            printf("%s\n", replaceString(finishedEquasion, result, 0, end));

            free(result);
        }
    }

    return 0.0;
}
