#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	char *args[] = {"/bin/ls", "-l", NULL};
	char *envp[] = {NULL};

	if (execve("/bin/ls", args, envp) == -1) {
		perror("execve");
		exit(-1);
	}

	// This code will never be reached if execve succeeds.
	printf("This line will not be executed.\n");
	return 0;
}
