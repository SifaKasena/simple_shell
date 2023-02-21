#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 * exit_atoi - converts the exit status into an integer
 * @status: charcter string containing exit status
 * Return: converted integer
 */

int exit_atoi(char *status)
{
	unsigned int st = 0, i = 0;

	while (status[i] != '\0')
	{
		if (status[i] > '9' || status[i] < '0')
		{
			printf("Illegal number: %s\n", status);
			return (-1);
		}
		st += status[i] - '0';
		if (st > INT_MAX)
		{
			printf("Illegal number: %s\n", status);
			return (-1);
		}
		if (status[i + 1] != '\0')
			st *= 10;
		i++;
	}

	return (st);
}
