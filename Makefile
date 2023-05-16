NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRCS = ft_split.c ft_substr.c get_next_line.c get_next_line_utils.c map.c moveplayer.c check.c checkpath.c
OBJS = $(SRCS:.c=.o)


$(NAME) : ${OBJS}
	$(CC) $(CFLAGS) ${OBJS} -Lmlx -lmlx -framework OpenGL -framework AppKit  -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)
fclean:
	@rm -f $(OBJS)
	rm -f $(NAME) 

re:	fclean all

.PHONY: all clean fclean re
