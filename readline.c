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

// give me an example of a command passed to lexer
// "ls -l | grep -i main.c"
// what should this command be after being passed to lexer
// "ls" "-l" "|" "grep" "-i" "main.c"
// what should the lexer return
// a linked list of tokens
// what should each token contain
// the value of the token and the type of the token
// what are the types of tokens
// "command" "argument" "pipe" "redirection" "semicolon" "newline"
// what is the value of a token
// the string that the token represents


int main(void) {

	char *input = readline("Input Here: ");
	printf("the user input is: %s\n", input);
	
	t_token *result = lexer(input);

	return 0;
}
