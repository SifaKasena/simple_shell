#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
	pid_t child_pid;
	char *line = NULL;
	char *argv[] = {NULL};
	size_t n = 0;
	int status;

	while (1)
	{
		printf("$ ");
		if (getline(&line, &n, stdin) == -1)
			break;
		line = strtok(line, "\n");
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(line, argv, NULL) == -1)
			{
				perror("Error:");
				return (1);
			}
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
