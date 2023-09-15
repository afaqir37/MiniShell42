#include <stdio.h>
#include <readline/readline.h>

int main(void) {
	char *input = readline("Input Here: ");
	printf("the user input is: %s\n", input);
	return 0;
}
