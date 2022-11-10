#include <stdbool.h>

bool isOperator(char op) {
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%' || op == '^') {
        return true;
    }

    return false;
}