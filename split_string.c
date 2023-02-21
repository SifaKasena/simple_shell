#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * split_string - splits a string into words
 * @s: string to parse
 * @c: delimeter
 * Return: array of words ending with NULL
 */

char **split_string(char *s, char *c)
{
	char **words = malloc(sizeof(*words));
	int i = 0;

	if (s == NULL || *s == '\0')
		return (NULL);

	words[i] = _strtok(s, c);
	while (words[i] != NULL)
	{
		i++;
		words = realloc(words, sizeof(*words) * (i + 1));
		words[i] = _strtok(NULL, c);
	}
	return (words);
}
