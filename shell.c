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
	char *line;
	char **commands;
	size_t n = 0;
	int broken;

	while (1)
	{
		broken = 0;
		line = NULL;
		printf("$");
		if (getline(&line, &n, stdin) == -1)
		{
			free(line);
			break;
		}
		line = _strtok(line, "\n");
		if (line == NULL)
			continue;
		commands = split_string(line, ";");
		broken = call_commands(commands);
		free(line);
		free(commands);
		if (broken != -1)
			return (broken);
	}
	return (0);
}

/**
 * call_child - Executes a command in a child process
 * @argv: list of arguments the first being the command
 * @envp: environment variables
 * Return: always 0 (success) 1 on Error
 */

int call_child(char **argv, char **envp)
{
	int status;
	pid_t child_pid;

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

	return (0);
}

/**
 * call_commands - calls commands one by one from an an array
 * @commands: array of commands
 * Return: 1 if loop breaks 0 otherwise
 */

int call_commands(char **commands)
{
	struct stat st;
	char **argv, **envp = environ;
	int state, i = 0, val = 0;

	while (commands[i] != NULL)
	{
		state = 0;
		argv = split_string(commands[i], " ");
		if (stat(argv[0], &st) == -1)
		{
			if (strcmp(argv[0], "exit") == 0)
			{
				if (argv[1] != NULL)
					val = exit_atoi(argv[1]);
				free(argv);
				return (val);
			}
			argv[0] = _which(argv[0]);
			if (argv[0] == NULL)
			{
				free(argv);
				perror("./shell");
				break;
			}
			else
				state = 1;
		}
		call_child(argv, envp);
		if (state)
			free(argv[0]);
		free(argv);
		i++;
	}
	return (-1);
}
