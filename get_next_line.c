#include <stdio.h>
#include "get_next_line.h"

int get_next_line(int const fd, char **lines)
{
    char **accumulator;
    char *buff;
    int line_counter = 0;

    size_t sz = 8;

    buff = (char * ) malloc(sizeof(char)  * (sz + 1));
    accumulator  = (char **) malloc(sizeof(char*) * (2));
    char * empty = (char *)malloc(1);
    *empty = '\0';
    *accumulator = empty;

    // Будет выполняться в цикле:

    read(fd, buff, sz);
    buff[sz] = '\0';
    accumulator++;
    *accumulator = buff;
    accumulator--;
    while(!check_line(accumulator)){
        accumulator++;
        read(fd, *accumulator, sz);
        accumulator--;
    }
    accumulator++;
    *lines = *accumulator;
    accumulator--;
    line_counter++;
    //char **new_lines = (char **) malloc(sizeof(char*) * (line_counter));
    return 1;
}
