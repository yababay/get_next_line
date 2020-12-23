#include <stdio.h>
#include "get_next_line.h"

static char **accumulator;
static int first = 1;
static char *buff;
static char *empty;
static size_t sz = BUFFER_SIZE;

int get_next_line(int const fd, char **lines)
{
    if(!first && **accumulator == '\n'){
        *accumulator += 1;
        *lines = empty;
        return 1;
    }
    if(first){
        buff = (char * ) malloc(sizeof(char)  * (sz + 1));
        empty = (char * ) malloc(sizeof(char)  * (1));
        *empty = '\0';
        buff[sz] = '\0';
        accumulator   = (char **) malloc(sizeof(char*) * (2));
        *accumulator  = (char *)malloc(1);
        **accumulator = '\0';
        accumulator++;
        *accumulator = buff;
        accumulator--;
    }
    while(first || !check_line(accumulator)){
        first = 0;
        accumulator++;
        size_t result = read(fd, *accumulator, sz);
        if(result < sz)
        {
            char *tmp = *accumulator; 
            int c = result;
            while(c){
                tmp++;
                c--;
            }
            *tmp = '\0';
            accumulator--;
            check_line(accumulator);
            accumulator++;
            *lines = *accumulator;
            return 0;
        }
        accumulator--;
    }
    accumulator++;
    *lines = *accumulator;
    buff[0] = '\0';
    *accumulator = buff;
    accumulator--;
    
    return 1;
}
