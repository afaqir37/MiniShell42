#include "minishell.h"


void _print_token(t_token *token)
{
	while (token)
	{
		printf(" ----- %s<   %d\n", token->content, token->space_check);
		token = token->next;
	}
}

int main(void) {
	while (1)
	{
		char *input = readline("Input Here: ");
		if (input && *input)
			add_history(input);
		t_token *result = _lexer(input);
		//_expander(&result);
		_print_token(result);
		//printf("the user input is: %s\n", input);
		free(input);
	

	}

	return 0;
}
