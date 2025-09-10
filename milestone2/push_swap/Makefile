CC = gcc
FLAGS = -Wall -Wextra -Werror -g -fPIC
NAME = PUSH_SWAP

SRC_LIB = libft

LIBFT = $(SRC_LIB)/libft.a
INCS = -I$(SRC_LIB) -I$(SRC_MLX) -I.

SRC = push_swap.c ft_atoi_checker.c arg_reader.c error_utils.c
OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ) $(LIBFT) $(MLX_LIB)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT)  -lglfw -lm -ldl -lpthread -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(FLAGS) $(INCS) -c $< -o $@

$(LIBFT):
	make -C $(SRC_LIB) CFLAGS="$(FLAGS)"

clean:
	rm -f $(OBJ)
	make -C $(SRC_LIB) clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean $(NAME)

.PHONY: clean fclean re
