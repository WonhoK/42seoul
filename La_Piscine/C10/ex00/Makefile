CC = Gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_display_file
DIR = ./srcs

SRCS = display_file.c
OBJS = $(SRCS:.c=.o)
OBJECTS = $(patsubst %.o, $(DIR)/%.o, $(OBJS))

all : $(NAME)

$(DIR)/%.o : $(DIR)/%.c
		$(CC) $(CFLAGS) -c $^ -o $@

$(NAME) : $(OBJECTS)
		$(CC) $(CFLAGS) $^ -o $@

.PHONY: all clean fclean re

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all
