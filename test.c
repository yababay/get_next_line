#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>
//#include "../src/get_next_line.h"

int main(int argc, char **argv)
{
    /*
	int fd;
    if(argc > 2) return 1;

    fd = open(argv[1], O_RDONLY);
    printf("%ld\n", fd);
    //close(fd);
*/
    while ((ret = get_next_line(0, &buff)) > 0)
        printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
    if (ret == -1)
        printf("-----------\nError\n");
    else if (ret == 0)
        printf("-----------\nEnd of stdin\n");
    close(fd);
    return 0;
}
