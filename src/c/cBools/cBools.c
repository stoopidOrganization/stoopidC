#include <string.h>
#include <stdio.h>

int isComparator(const char comp[]) {
    printf("Comp: %s\n", comp);

    if (!strcmp(comp, "<<") || !strcmp(comp, "<=") || !strcmp(comp, ">>") || !strcmp(comp, ">=") || !strcmp(comp, "==") || !strcmp(comp, "!=")) {
        return 1;
    }

    return 0;
}

int solveDoubleBool(double num1, const char comp[], double num2) {

    return 0;
}