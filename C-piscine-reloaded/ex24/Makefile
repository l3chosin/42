CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)
SRC_DIR = srcs
INC_DIR = includes
SRC = $(wildcard $(SRC_DIR)/*.c)
INC = $(wildcard $(INC_DIR)/*.h)
TARGET_DIR = ex24
TARGET = $(TARGET_DIR)/libft.a

all:	$(TARGET)

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET):	$(OBJ)
	ar rcs $@ $^

clean:
	rm	-f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re:	fclean all
