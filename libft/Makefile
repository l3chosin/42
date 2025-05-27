NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

SRC_DIR = .
INC_DIR = .
OBJ_DIR = obj
LIB_NAME = libft.a

SRC = ft_atoi.c\
ft_bzero.c\
ft_calloc.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_isprint.c\
ft_itoa.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memmove.c\
ft_memset.c\
ft_split.c\
ft_strchr.c\
ft_strdup.c\
ft_strjoin.c\
ft_strlcat.c\
ft_strlcpy.c\
ft_strlen.c\
ft_strncmp.c\
ft_strnstr.c\
ft_strrchr.c\
ft_strtrim.c\
ft_substr.c\
ft_tolower.c\
ft_toupper.c

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS)	-I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(LIB_NAME)

re: fclean all

.PHONY: all clean fclean re
