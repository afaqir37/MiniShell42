#include "minishell.h"




int main(void) {
	while (1)
	{
		char *input = readline("Input Here: ");
		if (input && *input)
			add_history(input);
		t_token *result = _lexer(input);
		printf("the user input is: %s\n", input);
		free(input);
	

	}

	return 0;
}
