CFLAGS = -Wall -Wextra -Werror
NAME = minishell
SRC = lexer.c readline.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
RM = rm -rf

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)
	make -C libft clean

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)


