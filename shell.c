#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
 * main - entry point
 * Description: shell mimic
 * Return: always 0 (success)
 */

int main(void)
{
	struct stat st;
	pid_t child_pid;
	char *line = NULL;
	char **envp = environ;
	char **argv;
	size_t n = 0;
	int status;

	while (1)
	{
		printf("$ ");
		if (getline(&line, &n, stdin) == -1)
			break;
		line = strtok(line, "\n");
		argv = split_string(line, " ");
		if (stat(argv[0], &st) == -1)
		{
			if (strcmp(argv[0], "exit") == 0)
				break;
			argv[0] = _which(argv[0]);
			if (argv[0] == NULL)
			{
				free(argv);
				printf("./shell: No such file\n");
				continue;
			}
		}
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("./shell");
			return (1);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, envp) == -1)
			{
				perror("./shell");
				return (1);
			}
		}
		else
		{
			wait(&status);
		}
		free(argv[0]);
		free(argv);
	}
	return (0);
}
