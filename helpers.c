#include <string.h>
#include <stdlib.h>


/**
 * split_string - splits a string into words
 * @s: string to parse
 * Return: array of words ending with NULL
 */

char **split_string(char *s)
{
	char *word, **words = malloc(sizeof(*words));
	int i = 0;

	if (s == NULL || *s == '\0')
		return (NULL);
	word = strtok(s, " ");

	while (word != NULL)
	{
		words[i] = word;
		i++;
		word = strtok(NULL, " ");
		words = realloc(words, sizeof(*words) * (i + 1));
	}
	words[i] = NULL;
	return (words);
}
