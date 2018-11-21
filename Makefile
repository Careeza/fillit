NAME = fillit

SRCS = ft_verif.c main.c ft_algo.c

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@make -C ./libft
	@gcc $(FLAGS) -c $(SRCS)
	@gcc $(FLAGS) $(OBJ) -o $(NAME) -Llibft -lft -I libft

clean:
	/bin/rm -rf $(OBJ)
	@make -C ./libft clean

fclean: clean
	/bin/rm -rf $(NAME)
	@make -C ./libft fclean

re: fclean all
