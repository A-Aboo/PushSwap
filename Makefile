NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iinclude

SRC = main.c \
	error.c \
	utils_char.c \
	utils_check.c \
	parse.c \
	stack.c \
	compress.c \
	ops_swap.c \
	ops_push.c \
	ops_rotate.c \
	ops_reverse_rotate.c \
	sort_small.c \
	sort_chunk.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c include/push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ) src/*.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
