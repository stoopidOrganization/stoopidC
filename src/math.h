#ifndef MATH_H
#define MATH_H
#include <stdbool.h>

double solveSimpleEquasion(double num1, char operator ,double num2);

double mathPower(double num1, int num2);

double mathModulo(double num1, double num2);

double solveComplexEquasion(char* equasion);

bool isOperator(char op);

#endif