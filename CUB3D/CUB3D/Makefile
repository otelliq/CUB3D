NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g 
SRC =  ./libft/*.c ./get_next_line/*.c *.c

.SILENT:

all: $(NAME)
$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME): $(SRC)
	printf "\033[32mcompiling...\033[0m\n"
	$(CC) $(CFLAGS) $(SRC) -o $@ -I./libft -L./libft -lft
	printf "\033[32mDONE\033[0m\n"

clean:
	make clean -C ./libft
	rm -f $(NAME)

fclean: clean
	printf "\033[31mcleaning...\033[0m\n"
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all
