NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP
DEPS = $(OBJ:.o=.d)

SRC_DIR = .
INC_DIR = .
OBJ_DIR = obj

SRC = ft_


OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)

-include $(DEPS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS)	-I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
