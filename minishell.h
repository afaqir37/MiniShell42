#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>

typedef struct s_token {
	char			*content;
	char			*type;
	enum e_state	stat;
	int				index;
	struct s_token	*next;
} t_token;

enum e_token_type {
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
	HERE_DOC
};

enum e_state {
	IN_DQUOTE,
	IN_QUOTE,
	GENERAL
};

t_token *_lexer(char *input);

#endif