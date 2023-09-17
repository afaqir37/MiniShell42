#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	if(argc > 1) {
		const char *s = getenv(argv[1]);
		printf("Variable: %s\n", s);
	} else {
		printf("Invalid Input\n");
	}
}
