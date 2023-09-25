#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "libft/libft.h"


// typedef struct s_list {
// 	t_token			*head;
// 	t_token			*tail;
// 	int				size;
// }	t_list;
enum e_state {
	GENERAL,
	IN_QUOTE,
	IN_DQUOTE,
	QUOTED
};

enum e_token{
	WORD = -1,
	WHITE_SPACE = ' ',
	NEW_LINE = '\n',
	QUOTE = '\'',
	DOUBLE_QUOTE = '\"',
	PIPE = '|',
	ESCAPE = '\\',
	ENV = '$',
	REDIRECT_IN = '<',
	REDIRECT_OUT = '>',
	REDIRECT_APPEND,
	HERE_DOC
};

typedef struct s_token {
	char			*content;
	enum e_token	type;
	enum e_state	state;
	char			*before_expanded;
	int				space_check;
	struct s_token	*next;
} t_token;

typedef struct s_commands {
	int					in_file;
	int					out_file;
	char				**cmd;
	struct s_commands	*next;
} t_commands;


//	-----------------------    PARSING    ------------------------


t_token*	_lexer(char *input);
t_token*    _create_token(char *value, enum e_token type, enum e_state state, int check_space);
void		_add_token(t_token **head, t_token *new);
void		_update_tokens(t_token **result);
int			_it_contains(int c);
void		_expander(t_token **head);
char*		_append(char *str, char c);
int			_syntax_check(t_token** result);
t_commands  *_parser(t_token **result);
t_commands  *_create_command(char **commands, int in_file, int out_file);
void		_add_command(t_commands **head, t_commands *new);
void		_print_array(char **array);


//	-----------------------    PARSING    ------------------------


#endif
