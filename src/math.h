#ifndef MATH_H
#define MATH_H
#include <stdbool.h>

double solveSimpleEquasion(double num1, char operator ,double num2);

double mathModulo(double num1, double num2);

char* solveComplexEquasion(char* equasion);

bool isOperator(char op);

#endif