#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
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
	IN_DQUOTE
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

t_token*	_lexer(char *input);
t_token*    _create_token(char *value, enum e_token type, enum e_state state, int check_space);
void		_add_token(t_token **head, t_token *new);
int			_it_contains(int c);
void		_expander(t_token **head);
char*		_append(char *str, char c);

#endif
