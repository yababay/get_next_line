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

int check_line(char **accumulator){
    char *fresh = get_fresh(accumulator);
    int result = fill_the_fresh(accumulator, fresh);
    printf("fresh=%s\n", fresh);
    if(*accumulator && *fresh) return 0;
    return 1;
}

char* get_fresh(char **accumulator){
    int c = 0;
    char *top = *accumulator;
    accumulator++;
    char *bottom = *accumulator;
    accumulator--;
    while(*top++) c++;
    while(*bottom && *bottom != '\n') {c++; bottom++;}
    printf("cnt=%d\n", c);
    char *tmp = (char*) malloc(c + 1);
    tmp[c] = '\0';
    return tmp;
}
