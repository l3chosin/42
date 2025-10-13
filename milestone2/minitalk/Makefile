NAME_CLIENT = client
NAME_SERVER = server
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_CLIENT = client.c
SRC_SERVER = server.c

all: $(LIBFT) $(NAME_CLIENT) $(NAME_SERVER)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME_CLIENT): $(SRC_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_CLIENT) -L$(LIBFT_DIR) -lft -o $(NAME_CLIENT)

$(NAME_SERVER): $(SRC_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_SERVER) -L$(LIBFT_DIR) -lft -o $(NAME_SERVER)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all
