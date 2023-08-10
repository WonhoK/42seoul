CC = Gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
INCLUDE = ./includes
DIR = ./srcs
SRCS = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJS = $(SRCS:.c=.o)
OBJECTS = $(patsubst %.o, srcs/%.o, $(OBJS))

all : $(NAME)

$(DIR)/%.o : $(DIR)/%.c
		$(CC) $(CFLAGS) -I $(INCLUDE) -c $^ -o $@

$(NAME) : $(OBJECTS)
		ar rcs $@ $^

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
