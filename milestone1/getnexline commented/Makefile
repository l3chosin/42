CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = a.out
LIBNAME = libft.a

SRCS_LIB = get_next_line.c get_next_line_utils.c
OBJS_LIB = $(SRCS_LIB:.c=.o)

SRCS_MAIN = main.c
OBJS_MAIN = $(SRCS_MAIN:.c=.o)

all: $(LIBNAME) $(NAME)

$(LIBNAME): $(OBJS_LIB)
	ar rcs $(LIBNAME) $(OBJS_LIB)

$(NAME): $(OBJS_MAIN) $(LIBNAME)
	$(CC) $(CFLAGS) $(OBJS_MAIN) -L. -lft -o $(NAME)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_LIB) $(OBJS_MAIN)

fclean: clean
	rm -f $(NAME) $(LIBNAME)

re: fclean all

.PHONY: all clean fclean re
