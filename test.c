#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>
//#include "../src/get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
    char *buff;
    char **text;
    size_t sz = 80;

    buff = (char * ) malloc(sizeof(char)  * (sz + 1));
    text = (char **) malloc(sizeof(char*) * (2));

    const char *hello = "Hello, ";
    const char *world = "World!" ;

    char *mem1 = (char*) malloc(10);
    char *mem2 = (char*) malloc(10);

    char *m1 = mem1;
    char *m2 = mem2;

    *text = m1;
    text++;
    *text = m2;

    while(*hello) *mem1++ = *hello++;
    while(*world) *mem2++ = *world++;

    *mem1 = '\0';
    *mem2 = '\0';

    printf("%s%s\n", *--text, *text);

    /*
    if(argc > 2) return 1;

    fd = open(argv[1], O_RDONLY);

    read(fd, buff, sz);

    buff[sz] = '\0';

    while(*buff){
        printf("%c\n", *buff);
        if(*buff == '\n'){
            *buff = '\0';
            *text = buff;
            break;
        }
        buff++;
    }

    printf("%s\n", &(text[0]));

    close(fd);
    */
    return 0;
}
