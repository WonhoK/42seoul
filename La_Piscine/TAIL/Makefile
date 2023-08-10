CC = Gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_tail
DIR = ./srcs
INCLUDE = ./includes

SRCS = ft_tail.c ft_buffer.c ft_string.c ft_print.c main.c
OBJS = $(SRCS:.c=.o)
OBJECTS = $(patsubst %.o, $(DIR)/%.o, $(OBJS))

all : $(NAME)

$(DIR)/%.o : $(DIR)/%.c
		$(CC) $(CFLAGS) -I $(INCLUDE) -c $^ -o $@

$(NAME) : $(OBJECTS)
		$(CC) $(CFLAGS) $^ -o $@

.PHONY: all clean fclean re

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all
