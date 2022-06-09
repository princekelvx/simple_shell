#include "main.h"

/**
 * free_dp - frees all the memory allocated to command
 * @command: pointer to allocated memory to free
 * Return: Nil
 */

void free_dp(char **command)
{
	size_t i = 0;

	if (command == NULL)
		return;

	while (command[i])
	{
		free(command[i]);
		i++;
	}

	if (command[i] == NULL)
		free(command[i]);
	free(command);
}

/**
 * free_exit - frees all the memory allocated and also exit
 * @command: the pointer to allocated command memory to free
 * Return: Nil
 */

void free_exit(char **command)
{
	size_t i = 0;

	if (command == NULL)
		return;

	while (command[i])
	{
		free(command[i]);
		i++;
	}

	if (command[i] == NULL)
		free(command[i]);
	free(command);
	exit(EXIT_FAILURE);
}
