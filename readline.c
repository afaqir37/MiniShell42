#include "minishell.h"


void _print_token(t_token *token)
{
		printf("-----------------------------------------------\n");

	while (token)
	{
		printf("[content]: %s\n", token->content);
		printf("[type]: %d\n", token->type);
		printf("[state]: %d\n", token->state);
		printf("[before_expanded]: %s\n", token->before_expanded);
		printf("[space_check]: %d\n", token->space_check);
		printf("-----------------------------------------------\n");
		token = token->next;
	}
}

void	_print_commands(t_commands *commands)
{
	int i = 0;
	printf("$-----------------commands---------------------$\n");
	while (commands)
	{
		_print_array(commands->cmd);
		printf("in_file: %d\n", commands->in_file);
		printf("out_file: %d\n", commands->out_file);
		printf("-----------------------------------------------\n");
		commands = commands->next;
		i++;
	}
}

int main(void) {
	while (1)
	{
		char *input = readline("Input Here: ");
		if (input && *input)
			add_history(input);
		t_token *result = _lexer(input);
		if (!result)
			continue;
		if(_syntax_check(&result))
			continue;
		_expander(&result);
		_update_tokens(&result);
		//_print_token(result);
		 t_commands *commands = _parser(&result);
		 _print_commands(commands);
		free(input);
	

	}

	return 0;
}
