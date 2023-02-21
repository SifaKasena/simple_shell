#include "main.h"
#include <stdlib.h>

/**
 * _strtok - strtok mimic
 * @str: string to tokenise
 * @delim: delimeters
 * Return: character pointer pointing to the successive word
 */

char *_strtok(char *str, const char *delim)
{
	static char *s;
	char *token;
	int i, j, state = 0;

	if (str != NULL)
		s = str;
	else if (*s == '\0')
		return (NULL);

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (s[i] == delim[j])
			{
				s[i] = '\0';
				if (state)
				{
					s = s + i + 1;
					return (token);
				}
				else if (s[i] == '\0')
					break;
			}
		}
		if (s[i] != '\0' && state == 0)
		{
			token = s + i;
			state = 1;
		}
	}
	if (state)
	{
		s = s + i;
		return (token);
	}
	return (NULL);
}
