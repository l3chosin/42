NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP
AR = ar
ARFLAGS = rcs
DEPS = $(OBJ:.o=.d)

SRC_DIR = .
INC_DIR = .
OBJ_DIR = obj

SRC = ft_printchar.c\
	ft_printnbr.c\
	ft_printhex.c\
	ft_printf.c\


OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

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
