CC = gcc
FLAGS = -Wall -Wextra -Werror -g -fPIC
NAME = push_swap

SRC_LIB = libft
LIBFT = $(SRC_LIB)/libft.a
INCS = -I$(SRC_LIB) -I.

# Headers para dependencias
HEADERS = push_swap.h

SRC = push_swap.c \
	arg_reader.c \
	array_to_list.c \
	error_utils.c \
	ft_atoi_checker.c \
	utils.c \
	more_utils.c \
	even_more_utils.c \
	movements/push.c \
	movements/reverse_rotate.c \
	movements/rotate.c \
	movements/swap.c \
	sorter/ft_sorter.c \
	sorter/first_push.c \
	sorter/sort_utils.c \
	sorter/big_case.c \
	sorter/big_case_utils.c

OBJ_DIR = obj
OBJ_SUBDIR = obj/movements obj/sorter
OBJ = $(SRC:%.c=obj/%.o)

all: $(OBJ_DIR) $(OBJ_SUBDIR) $(NAME)

$(OBJ_DIR) $(OBJ_SUBDIR):
	mkdir -p $@

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) $(INCS) -c $< -o $@

$(LIBFT):
	make -C $(SRC_LIB) CFLAGS="$(FLAGS)"

clean:
	rm -f $(OBJ)
	make -C $(SRC_LIB) clean

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	make -C libft fclean

re: fclean $(NAME)

.PHONY: clean fclean re
