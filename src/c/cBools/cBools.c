#include <string.h>

int isBool(const char input[]) {
    if (!strcmp(input, "0") || !strcmp(input, "1")) {
        return 1;
    }

    return 0;
}

int strToBool(const char input[]) {
    if (!strcmp(input, "0")) {
        return 0;
    } else if (!strcmp(input, "1")) {
        return 1;
    }

    return -1;
}

int isComparator(const char comp[]) {
    if (!strcmp(comp, "<<") || !strcmp(comp, "<=") || !strcmp(comp, ">>") || !strcmp(comp, ">=") || !strcmp(comp, "==") || !strcmp(comp, "!=")) {
        return 1;
    }

    return 0;
}

int isCombiner(const char comb[]) {
    if (!strcmp(comb, "&&") || !strcmp(comb, "||")) {
        return 1;
    }

    return 0;
}

int solveDoubleBool(double num1, const char comp[], double num2) {
    if (!strcmp(comp, "<<")) {
        if (num1 < num2) return 1;

        return 0;
    } else if (!strcmp(comp, "<=")) {
        if (num1 <= num2) return 1;

        return 0;
    } else if (!strcmp(comp, ">>")) {
        if (num1 > num2) return 1;
            
        return 0;
    } else if (!strcmp(comp, ">=")) {
        if (num1 >= num2) return 1;
        
        return 0;
    } else if (!strcmp(comp, "==")) {
        if (num1 == num2) return 1;
        
        return 0;
    } else if (!strcmp(comp, "!=")) {
        if (num1 != num2) return 1;
        
        return 0;
    }

    return -1;
}

int solveStringBool(const char str1[], const char comp[], const char str2[]) {
    if (!strcmp(comp, "==")) {
        if (!strcmp(str1, str2)) return 1;

        return 0;
    } else if (!strcmp(comp, "!=")) {
        if (strcmp(str1, str2)) return 1;

        return 0;
    }

    return -1;
}

int solveCombiner(int bool1, const char comb[], int bool2) {
    if (!strcmp(comb, "&&")) {
        if(bool1 && bool2) {
            return 1;
        } else {
            return 0;
        }
    } else if (!strcmp(comb, "||")) {
        if (bool1 || bool2) {
            return 1;
        } else {
            return 0;
        }
    }

    return -1;
}