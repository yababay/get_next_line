#include <stdio.h>
#include "get_next_line.h"

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
    char *fresh = (char*) malloc(c + 1);
    fresh[c] = '\0';
    return fresh;
}

int check_line(char **accumulator){  //ne popalsya li perevod stroki //top = acc 
    char *fresh = get_fresh(accumulator); //poluchit acc podhodyashego razmera
    int result = fill_the_fresh(accumulator, fresh); //zapolnyaem, esli est perevod stroki to result = 1, else = 0
    if(result) {
        accumulator++;
        char *bottom = *accumulator;
        while(*bottom != '\n'){bottom++;}
        if(*bottom == '\n') {bottom++;}
        *accumulator = fresh;
        accumulator--;
        *accumulator = bottom;
        return 1; //we found new line
    }
    *accumulator = fresh;
    return 0;
}

//top - dla sborki
//bottom - now buff 
//acc[0] - top
//acc[1] - bottom
//when "lamb\nLittle" to rechnage place top and bottom