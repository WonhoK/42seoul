CC = Gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_cat
DIR = ./srcs
INCLUDE = ./includes

SRCS = display_file.c ft_putstr.c print_error.c ft_strcmp.c main.c
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
