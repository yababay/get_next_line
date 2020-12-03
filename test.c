#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>
//#include "../src/get_next_line.h"

static int check_buff(char **text)
{
    //nt c = 0;
    //while(*buff){buff++; c++;}
    printf("acc=%s\n", *text);
    text++;
    printf("buff=%s\n", *text);
    text--;
    return 0;
}

int main(int argc, char **argv)
{
    if(argc > 2) return 1;

	int fd;
    char *buff;
    char **text;
    size_t sz = 8;

    buff = (char * ) malloc(sizeof(char)  * (sz + 1));
    text = (char **) malloc(sizeof(char*) * (2));
    char * empty = (char *)malloc(1);
    *empty = '\0';
    *text = empty;

    fd = open(argv[1], O_RDONLY);

    int c = 5;

    while(c--){
        read(fd, buff, sz);
        buff[sz] = '\0';
        text++;
        *text = buff;
        text--;
        int ok = check_buff(text);
        }

    close(fd);

    return 0;
}
