NAME   = get_next_line.a
SRCS   = get_next_line.c \
		 get_next_line_utils.c 

OBJS   = ${SRCS:.c=.o}
CC     = gcc
RM     = rm -rf
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=32

%.o: %.c
	${CC} ${CFLAGS} -c $<

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}
	ranlib ${NAME}

all: ${NAME} testc

clean: fclean tclean
	${RM} ${OBJS}

fclean:
	${RM} ${NAME}

tclean:
	${RM} test

testc:
	gcc -o test test.c get_next_line.o get_next_line_utils.o

re: clean all
