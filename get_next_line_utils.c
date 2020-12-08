#include <stdio.h>
#include "get_next_line.h"

// TODO: static

int fill_the_fresh(char **accumulator, char *fresh){
    char *top = *accumulator;
    accumulator++;
    char *bottom = *accumulator;
    accumulator--;
    while(*top) *fresh++ = *top++;
    while(*bottom && *bottom != '\n') {*fresh++ = *bottom++;}
    if(*bottom) return 1;
    return 0;
}

char* get_fresh(char **accumulator){
    int c = 0;
    char *top = *accumulator;
    accumulator++;
    char *bottom = *accumulator;
    accumulator--;
    while(*top++) c++;
    while(*bottom && *bottom != '\n') {c++; bottom++;}
    char *tmp = (char*) malloc(c + 1);
    tmp[c] = '\0';
    return tmp;
}

int check_line(char **accumulator){
    char *fresh = get_fresh(accumulator);
    int result = fill_the_fresh(accumulator, fresh);
    if(result) {
        accumulator++;
        char *bottom = *accumulator;
        while( *bottom != '\n'){bottom++;}
        bottom++;
        int c = 0;
        while(*bottom){bottom++; c++;}
        char *tmp = (char*)malloc(c + 1);
        char *tail = *accumulator;
        while(*tail){*tmp++ = *tail++;}
        *tmp = '\0';
        *accumulator = fresh;
        accumulator--;
        *accumulator = tmp;
        return 1; //we found new line
    }
    *accumulator = fresh;
    return 0;
}

