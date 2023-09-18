#include <stdio.h>
#include <readline/readline.h>

// i need to implement a minishell 42 project
// so the first step i need to do is implementing a lexer

// the lexer will take the input from the user and split it into tokens
// the tokens will be stored in a linked list
// the linked list will be used by the parser to build the AST

typedef struct s_token {
	char *value;
	char *type;
	struct s_token *next;
} t_token;

enum e_token_type {
	WORD = -1;
	WHITE_SPACE = ' ';
	NEW_LINE = '\n';
	QUOTE = '\'';
	DOUBLE_QUOTE = '\"';
	PIPE = '|';
	ESCAPE = '\\';
	ENV = '$';
	REDIRECT_IN = '<';
	REDIRECT_OUT = '>';
	HERE_DOC;
}

t_token*	_lexer(char *input)
{
	t_token *head;
	t_token *current;

	
}

int main(void) {

	char *input = readline("Input Here: ");
	t_token *result = _lexer(input);

	printf("the user input is: %s\n", input);
	
	t_token *result = lexer(input);


	return 0;
}
