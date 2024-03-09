NAME = so_long

NAME_B = so_long_bonus

CC = CC

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC =	utils_4_parsing.c \
		parsing.c \
		read_maps.c \
		so_long.c \
		get_next_line.c \
		utils_get_next_line.c \
		compare_put.c \
		parse_walls.c \
		backtracking.c \
		my_window.c \
		initialize.c \
		put_image_to_map.c \
		directionss.c \
		utils_2_move.c \
		putnbr.c \

SRC_B = /BONUS/backtracking_bonus.c \
		/BONUS/compare_put_bonus.c \
		/BONUS/directionss_bonus.c \
		/BONUS/gnl_bonus.c \
		/BONUS/initialize_bonus.c \
		/BONUS/my_window_bonus.c \
		/BONUS/parse_walls_bonus.c \
		/BONUS/parsing_bonus.c \
		/BONUS/put_image_to_map_bonus.c \
		/BONUS/read_maps_bonus.c \
		/BONUS/so_long_bonus.c \
		/BONUS/utils2move_bonus.c \
		/BONUS/utils4parsing_bonus.c \

OBJ = $(SRC:.c=.o)

OBJB = $(SRC_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit  -o $(NAME)

bonus: $(OBJB)
		$(CC) $(OBJB) -Imlx -c -o $(NAME_B)

$(NAME_B): $(OBJB)
			$(CC) $(OBJB) -lmlx -framework OpenGL -framework AppKit  -o $(NAME_B)

%.o : %.c so_long.h so_long_bonus.h
		$(CC) $(CFLAGS)  -Imlx -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJB)

fclean: clean
	$(RM) $(NAME) $(NAME_B)

re: fclean all

.PHONY: all clean fclean re