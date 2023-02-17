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
	char *pathname;
	char **paths = split_string(_getenv("PATH"), ":");
	int i = 0;

	while (1)
	{
		if (paths[i] == NULL)
		{
			free(paths);
			return (NULL);
		}
		pathname = strdup(paths[i]);
		pathname = strcat(pathname, "/");
		pathname = strcat(pathname, file);
		if (stat(pathname, &st) == 0)
			break;
		free(pathname);
		i++;
	}
	free(paths);
	return(pathname);
}
/*
int main(int ac, char **av)
{
	int i;
	char *p;

	if (ac < 2)
	{
		printf ("Usage: %s <commands> ...\n", av[0]);
		return (1);
	}
	for (i = 1; i < ac; i++)
	{
		p = _which(av[i]);
		if (p != NULL)
			printf("%s\n", p);
		else
			printf("Not found.\n");
		free(p);
	}
	return (0);
}*/
