CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I$(INC_DIR)
SRC_DIR	=	srcs
INC_DIR	=	includes
SRC	=	srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
TARGET	=	libft.a
OBJ	=	$(SRC:.c=.o)

all:	$(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET):	$(OBJ)
	ar	rcs	$@	$^

clean:
	rm	-f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re:	fclean all
