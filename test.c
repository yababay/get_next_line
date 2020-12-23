#include <stdio.h>
#include "./get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
    char *line;
    int result; //1 if file not ended, 0 if file end
    int count = 1;

    fd = (argc == 1 ? 0 : open(argv[1], O_RDONLY));
    while(1){
        result = get_next_line(fd, &line);
        printf("%d) %s %d\n", count, line, result);
        if(!result) break;
        count++;
    }
    close(fd);
    return 0;
}