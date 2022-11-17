#include <string.h>
#include "../../cpp/utils/utils.hpp"

int isBool(const char input[]) {
    return (!strcmp(input, "0") || !strcmp(input, "1") || !strcmp(input, "false") || !strcmp(input, "true"));
}

int strToBool(const char input[]) {
    if (!strcmp(input, "0") || !strcmp(input, "false")) {
        return 0;
    } else if (!strcmp(input, "1") || !strcmp(input, "true")) {
        return 1;
    }

    return -1;
}

int isComparator(const char comp[]) {
    return (!strcmp(comp, "<<") || !strcmp(comp, "<=") || !strcmp(comp, ">>") || !strcmp(comp, ">=") || !strcmp(comp, "==") || !strcmp(comp, "!="));
}

int isCombiner(const char comb[]) {
    if (!strcmp(comb, "&&") || !strcmp(comb, "||")) {
        return 1;
    }

    return 0;
}

int solveDoubleBool(double num1, const char comp[], double num2) {
    if (!strcmp(comp, "<<")) {
        return (num1 < num2);
    } else if (!strcmp(comp, "<=")) {
        return (num1 <= num2);
    } else if (!strcmp(comp, ">>")) {
        return (num1 > num2);
    } else if (!strcmp(comp, ">=")) {
        return (num1 >= num2);
    } else if (!strcmp(comp, "==")) {
        return (num1 == num2);
    } else if (!strcmp(comp, "!=")) {
        return (num1 != num2);
    }

    return -1;
}

int solveStringBool(const char str1[], const char comp[], const char str2[]) {
    if (!strcmp(comp, "==")) {
        return (!strcmp(str1, str2));

    } else if (!strcmp(comp, "!=")) {
        return (strcmp(str1, str2));
    }

    return -1;
}

int solveCombiner(int bool1, const char comb[], int bool2) {
    if (!strcmp(comb, "&&")) {
        return(bool1 && bool2);
    } else if (!strcmp(comb, "||")) {
        return (bool1 || bool2);
    }

    return -1;
}