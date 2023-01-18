cc = gcc
INC = so_long.h get_next_line.h
FLAGS = -lmlx -framework OpenGL -framework AppKit
SRCS = map.c moveplayer.c get_next_line.c get_next_line_utils.c ft_split.c ft_substr.c checkpath.c check.c

OBJS = ${SRCS:.c=.o}
NAME = so_long.a get_next_line.a

all : $(NAME)

${NAME}:${OBJS}
		${LIBC} ${NAME} ${OBJS}

clean: 
	rm -f  $(OBJS)
fclean: clean
	rm -f ${NAME}

.PHONY: all clean