NAME = so_long

NAME_B = so_long_bonus

CC = CC

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = utils_4_parsing.c \
		parsing.c \
		read_maps.c \
		so_long.c \
		get_next_line.c \
		utils_get_next_line.c \
		compare_put.c \
		parse_walls.c \
		backtracking.c \

SRC_B =

OBJ = $(SRC:.c=.o)

OBJB = $(SRC_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

bonus: $(OBJB)
		$(CC) $(OBJB) -o $(NAME_B)

%.o : %.c so_long.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJB)

fclean: clean
	$(RM) $(NAME) $(NAME_B)

re: fclean all

.PHONY: all clean fclean re