#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _getenv - returns the value of an environment variable
 * @env: environment variable to get
 * Return: a character string that is the value of the variable
 */

char *_getenv(char *env)
{
	char *var, **envp = environ;
	int i = 0, j, k;

	while (envp[i] != NULL)
	{
		k = 0;
		var = envp[i];
		for (j = 0; var[j] != '='; j++)
		{
			if (env[k] == '\0')
				break;
			if (var[j] == env[k++])
				continue;
			else
				break;
		}
		if (var[j] == '=')
		{
			return (envp[i] + j + 1);
		}
		i++;
	}
	return (NULL);
}
