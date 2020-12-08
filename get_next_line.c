#include <stdio.h>
#include "get_next_line.h"

int get_next_line(int const fd, char **lines)
{
    char **accumulator;
    char *buff;

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
    printf("acc=%s\n", *accumulator);
    accumulator++;
    printf("buff=%s\n", *accumulator);
    accumulator--;
    int result = check_line(accumulator);

    if(0 && fd && *lines && result) return 1;
    return 1;
}
