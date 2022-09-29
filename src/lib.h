#ifndef LIB_H
#define LIB_H

int startsWith(char* str, char* pre);

int getSize(char* str);

char* split(char* str, char splitter, int index);

int charToInt(char value);

double strToDouble(char* value);

char* replaceString(char* string, char* replace, int start, int end);

#endif