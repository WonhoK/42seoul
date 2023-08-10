CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = rush-02
INCLUDE = ./includes

SRCS = srcs/ft_dict.c srcs/ft_errno.c srcs/ft_print.c srcs/ft_putstr.c srcs/ft_reader.c srcs/ft_split.c srcs/ft_strcmp.c srcs/ft_strcpy.c srcs/ft_string.c srcs/ft_strip.c srcs/main.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
		$(CC) $(CFLAGS) -I $(INCLUDE) -c $^ -o $@

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $^ -o $@

.PHONY: all clean fclean re

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all
