#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "lib.h"
#include "global.h"
#include "math.h"
#include <stdbool.h>

int startsWith(char* str, char* pre) {
    size_t lenpre = strlen(pre),
           lenstr = strlen(str);
    return lenstr < lenpre ? 0 : strncmp(pre, str, lenpre) == 0;
}

int getSize(char* str) {
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

char* split(char* str, char splitter, int index) {
    char* out = malloc(getSize(str));

    if(index == 0) {
        int j = 0;
    
        for(int i = 0; i < getSize(str); i++) {
            if(str[i] == splitter || str[i] == '\0') {
                out[j] = '\0';
                return out;
            }

            out[j] = str[i];
            j++;
        }
    } else {
        int j = index;

        for(int i = 0; i < getSize(str); i++) {
            if(str[i] == splitter) {
                j -= 1;
            }

            if(j == 0) {
                int k = 1;
                
                while (str[k + i] != splitter && k + 1 < getSize(str) && str[k + i] != '\n') {
                    out[k - 1] = str[k + i];
                    k++;
                }

                out[k - 1] = '\0';
                return out;
            }
        }
    }

    return str;
}

int charToInt(char value) {
    if(value == '0') {
        return 0;
    } else if(value == '1') {
        return 1;
    } else if(value == '2') {
        return 2;
    } else if(value == '3') {
        return 3;
    } else if(value == '4') {
        return 4;
    } else if(value == '5') {
        return 5;
    } else if(value == '6') {
        return 6;
    } else if(value == '7') {
        return 7;
    } else if(value == '8') {
        return 8;
    } else if(value == '9') {
        return 9;
    }

    return -1;
}

double strToDouble(char* value) {
    double newValue = 0;
    char op = value[0];
    int start;

    if(value[0] == '-') {
        op = '-';
        start = 1;
    } else {
        op = '+';
        start = 0;
    }

    for (int i = start; i < getSize(value) && value[i] != '\0'; i++) {
        if(value[i] == '.') {
            i++;
            int j = 1;
            while(i < getSize(value)) {
                if(op == '-') {
                    newValue = newValue - ((double)charToInt(value[i]) / pow(10, j));
                } else {
                    newValue = newValue + ((double)charToInt(value[i]) / pow(10, j));
                }
                i++;
                j++;
            }
            break;
        }

        if(newValue == 0) {
            if(op == '-') {
                newValue = -(double)charToInt(value[i]);
            } else {
                newValue = (double)charToInt(value[i]);
            }
        } else {
            if(op == '-') {
                newValue = (newValue * 10) - (double)charToInt(value[i]);
            } else {
                newValue = (newValue * 10) + (double)charToInt(value[i]);
            }
        }
    }

    return newValue;
}

char* replaceString(char* string, char* replace, int start, int end) {
    int size = getSize(string) + getSize(replace) + 1;
    char* result = malloc(size);

    int j = 0;
    int k = 0;

    for(int i = 0; i < size; i++) {
        if(i == start) {
            while(j < getSize(replace)) {
                result[i + j] = replace[j];
                j++;
            }

            i++;
            k = end;
        }

        result[i + j] = string[k];
        k++;
    }

    return result;
}