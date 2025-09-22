CC = gcc
FLAGS = -g -fPIC
NAME = PUSH_SWAP

SRC_LIB = libft

LIBFT = $(SRC_LIB)/libft.a
INCS = -I$(SRC_LIB) -I.

SRC = push_swap.c \
	ft_atoi_checker.c \
	arg_reader.c \
	error_utils.c \
	array_to_list.c \
	utils.c \
	utils_2.c \
	movements/push.c \
	movements/reverse_rotate.c \
	movements/rotate.c \
	movements/swap.c \
	sorter/ft_sorter.c \
	sorter/sort_utils.c \
	sorter/three_case.c \

OBJ_DIR = obj
OBJ_SUBDIR = obj/movements obj/sorter
OBJ = $(SRC:%.c=obj/%.o)

all: $(OBJ_DIR) $(OBJ_SUBDIR) $(NAME)

$(OBJ_DIR) $(OBJ_SUBDIR):
	mkdir -p $@

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
