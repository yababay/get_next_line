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
    char *line;
    int result;

    fd = open(argv[1], O_RDONLY);

    int count = 1;
    while(count < 15){
        result = get_next_line(fd, &line);
        printf("%d) %s\n", count, line);
        count++;
    }
    
    close(fd);

    return 0;
}
