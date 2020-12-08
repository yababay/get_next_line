#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>
#include "./get_next_line.h"

int main(int argc, char **argv)
{
    if(argc != 2){
        printf("There is nothing to read :(\n");
        return 1;
    } 

    printf("Testing read_next_line...\n");

	int fd;
    char **text;
    text = (char **) malloc(sizeof(char*) * (2));

    fd = open(argv[1], O_RDONLY);

    int result = get_next_line(fd, text);
    if(result) printf("The first line is %s\n", *text);
/*

    result = get_next_line(fd, text);
    if(result) printf("The second line is %s\n", *text);

    result = get_next_line(fd, text);
    if(result) printf("The third line is %s\n", *text);
*/
    close(fd);

    return 0;
}
