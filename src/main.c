#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lib.h"
#include "global.h"
#include "variables.h"
#include "math.h"

int main(int argc, char** argv) {
    // get the filename from the args
    char* filename = argv[1];
    if(filename == NULL) {
        filename = "test.stpd";
    }
    
    // get the system arguments
    bool silent = false;
    bool log = false;
    char* logname = "";
    for (size_t i = 0; i < argc; i++) {
        if(!strcmp(argv[i], "--silent")) {
           silent = true;
        }

        if(!strcmp(argv[i], "--log")) {
           log = true;
           logname = argv[i+1];
        }
    }

    //  open the logfile to write the output to
    FILE* logf;
    logf = fopen(logname,"w");

    // open the file
    FILE* program;
    program = fopen(filename, "r");
    if (NULL == program) {
        printf("file can't be opened \n");
        return 1;
    }
    int size=0;

    fclose(program);
    program = fopen(filename, "r");
    char sizebuf[lineLimit];
    while(1) {
        fgets(sizebuf, lineLimit, program);
        size++;
        //check for end of file
        if (feof(program)){
            break;
        }
    }

    char buf[lineLimit];
    char buf2[size][lineLimit];
    fclose(program);
    program = fopen(filename, "r");
    
    for(int i = 0; i < size; i++) {  
        fgets(buf, lineLimit, program);
        
        strcpy(buf2[i], buf);
    }
    
    fclose(program);

    printf("%f\n", strToDouble("88"));
    printf("%f\n", strToDouble("-88"));
    printf("%f\n", strToDouble("88.33"));
    printf("%f\n", strToDouble("-88.33"));

    for(int i = 0; i < size; i++) {
        char* currentKeyword = split(buf2[i], ':', 0);

        if(!strcmp(currentKeyword, "var")) {
            newVar(split(split(buf2[i], ':', 1), '=', 0), split(split(buf2[i], ':', 1), '=', 1));
        } else if(!strcmp(currentKeyword, "out")) {
            if(log) {
                fprintf(logf, "%s\n", getVal(split(buf2[i], ':', 1)));
            }
            if(!silent) {
                printf("%s\n", getVal(split(buf2[i], ':', 1)));
            }
            
        } else if(!startsWith(buf2[i], "#") && strcmp(currentKeyword, " ") > 0) {
            printf("Keyword %s not Found\n", currentKeyword);
            return 1;
        }
    }

    fclose(logf);
    return 0;
}