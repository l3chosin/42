CC		= cc
CFLAGS	= -Wall -Wextra -Werror -pthread -fsanitize=thread
NAME	= philo
SRC		= utils.c emulation.c actions.c main.c test_functions.c ft_atoi_checker.c prepare_emulation.c reaper.c
OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
