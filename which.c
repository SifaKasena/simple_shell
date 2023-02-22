#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * _which -  looks for files in PATH
 * @file: file name
 * Return: full path of found file NULL if not found
 */

char *_which(char *file)
{
	struct stat st;
	char *cmd;
	char *PATH = strdup(getenv("PATH"));
	char **paths = split_string(PATH, ":");
	int i = 0;

	while (1)
	{
		if (paths[i] == NULL)
		{
			free(PATH);
			free(paths);
			return (NULL);
		}
		cmd = strdup(paths[i]);
		cmd = realloc(cmd, strlen(cmd) + strlen(file) + 3);
		cmd = strcat(cmd, "/");
		cmd = strcat(cmd, file);
		if (stat(cmd, &st) == 0)
			break;
		free(cmd);
		i++;
	}
	free(PATH);
	free(paths);
	return (cmd);
}
