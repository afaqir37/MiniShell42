#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void){
	char *argv[] = {"/bin/ls", "-la", NULL};
	char *envp[] = {"HOME=/", "PATH=/bin:/usr/bin", "USER=brandon", NULL};

	int fd = open("/nfs/homes/afaqir/Desktop/minishell/ls.log", \
			O_WRONLY|O_CREAT|O_TRUNC,0666);
	dup2(fd, 1);
	close(fd);

	execve(argv[0], &argv[0], envp);
	fprintf(stderr, "Oops!\n"); // this line will be excecuted in case
				    // execve() function fails
	return -1;
}
