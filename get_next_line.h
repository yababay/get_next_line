#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int get_next_line(int const fd, char **line);
int check_line(char **accumulator);

#endif

