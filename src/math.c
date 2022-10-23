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

double getNum1(char* equasion, size_t operator) {
    double num1 = 0;
    int start = operator - 1;
    printf("%d\n", start);

    while(!isOperator(equasion[start - 1]) && start > 0) start--;

    printf("%d\n", start);

    return num1;
}

char* solveComplexEquasion(char* equasion) {
    char* finishedEquasion = equasion;
    // int numLimit = 1024;
    bool resolving = true;

    while(resolving) {
        // test if equasion is finished
        bool done = true;
        bool stage1 = false;
        bool stage2 = false;
        bool stage3 = false;

        for(size_t i = 0; i < getSize(finishedEquasion); i++) {
            if(isOperator(finishedEquasion[i])) {
                done = false;
            }
            
            if(finishedEquasion[i] == '^') {
                stage1 = true;
            } else if(finishedEquasion[i] == '*' || finishedEquasion[i] == '/' || finishedEquasion[i] == '%') {
                stage2 = true;
            } else if(finishedEquasion[i] == '+' || finishedEquasion[i] == '-') {
                stage3 = true;
            }
        }

        if(done) {
            resolving = false;
            break;
        }
        
        for(size_t i = 0; i < getSize(finishedEquasion); i++) {
            if(isOperator(finishedEquasion[i])) {
                getNum1(finishedEquasion, i);

                // resolving the equasion
                if(stage1) {
                    // TODO implement '^' here
                    printf("stage1");
                    resolving = false;
                    break;
                } else if(stage2 && !stage1) {
                    // TODO implement '*', '/', '%' here
                    printf("stage2");
                    resolving = false;
                    break;
                } else if(stage3 && !stage1 && !stage2) {
                    // TODO implement '+', '-' here
                    printf("stage3");
                    resolving = false;
                    break;
                }
            }
        }
        
        
    }

    return finishedEquasion;
}
