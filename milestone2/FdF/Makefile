CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = FDF

SRC_LIB = libft
SRC_MLX = mlx42

LIBFT = $(SRC_LIB)/libft.a
MLX_LIB = $(SRC_MLX)/linux/libmlx42.a
LIBS = -L$(SRC_LIB) -L$(SRC_MLX)/linux
INCS = -I$(SRC_LIB) -I$(SRC_MLX) -I.

SRC = fdf.c
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ) $(LIBFT) $(MLX_LIB)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) $(MLX_LIB) -lglfw -lm -ldl -lpthread -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(INCS) -c $< -o $@

$(LIBFT):
	make -C $(SRC_LIB)

$(MLX_LIB):
	make -C $(SRC_MLX)/linux

clean:
	rm -f $(OBJ)
	make -C $(SRC_LIB) clean
	make -C $(SRC_MLX) clean || true

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	rm -f $(MLX_LIB)

re: fclean $(NAME)

.PHONY: clean fclean re
