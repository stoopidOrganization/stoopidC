#include <math.h>
#include <stdio.h>

int isOperator(char op) {
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%' || op == '^') {
        return 1;
    }

    return 0;
}

int isCharNum(char num) {
    if (num == '-' || num == '.' || num == '0' || num == '1' || num == '2' || num == '3' || num == '4' || num == '5' || num == '6' || num == '7' || num == '8' || num == '9') {
        return 1;
    }

    return 0;
}

int calcOperatorScore(char op) {
    if (op == '+') {
        return 0;
    } else if (op == '-') {
        return 1;
    } else if (op == '*') {
        return 2;
    } else if (op == '/') {
        return 3;
    } else if (op == '%') {
        return 4;
    } else if (op == '^') {
        return 5;
    }

    return -1;
}

double solveSimpleEquasion(double num1, char op, double num2) {
    if (op == '+') {
        return num1 + num2;
    } else if (op == '-') {
        return num1 - num2;
    } else if (op == '*') {
        return num1 * num2;
    } else if (op == '/') {
        return num1 / num2;
    } else if (op == '%') {
        return fmod(num1, num2);
    } else if (op == '^') {
        return pow(num1, num2);
    }

    return -1;
}