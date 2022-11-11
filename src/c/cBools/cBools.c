#include <string.h>
#include <stdio.h>

int isComparator(const char comp[]) {
    printf("Comp: %s\n", comp);

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