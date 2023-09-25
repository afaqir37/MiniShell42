#CFLAGS = -Wall -Wextra -Werror
NAME = minishell
SRC = lexer.c readline.c utils_lexer.c tokens.c \
		expander.c update_tokens.c syntax_checker.c \
		parser.c commands.c
OBJ = $(SRC:.c=.o)
LIBFT = libft.a
RM = rm -rf

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lreadline libft/libft.a -o $(NAME)

re: fclean all

clean:
	$(RM) $(OBJ)
	make -C libft clean

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)


