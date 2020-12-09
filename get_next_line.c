#include <stdio.h>
#include "get_next_line.h"

int get_next_line(int const fd, char **lines)
{
    char **accumulator;
    char *buff;
    size_t line_counter = 0;

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
    /*accumulator++;
    *lines = *accumulator;
    accumulator--;
    */
    if(lines != NULL) { line_counter = sizeof((char**)lines);}
    line_counter++;
    printf("lines_c = %ld\n", line_counter);
    char **new_lines = (char **) malloc(sizeof(char*) * (line_counter));
    accumulator++;
    *new_lines = *accumulator;
    accumulator--;
    printf("new_line = %s\n", *new_lines);
    lines = new_lines; //TODO: put old lines in new container
    return 1;
}
