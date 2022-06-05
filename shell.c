#include "main.h"

/**
 * main - Entry point
 * @ac: numbr of input args
 * @av: pointer to array of input args
 * @env: pointer to array of enviroment variables
 * Return: Always 0
 */

int main(int ac, char **av, char **env)
{
	ssize_t line = 0;
	size_t size = 0;
	char *buff = NULL, **command = NULL;
	int cycles = 0;
	(void)ac;

	while (1)
	{
		cycles++;
		loop();
		signal(SIGINT, handle);
		line = getline(&buff, &size, stdin);
		if (line == EOF)
			_EOF(buff);
		else if (*buff == '\n')
			free(buff);
		else
		{
			buff[_strlen(buff) - 1] = '\0';
			command = tokening(buff, " \0");
			free(buff);
			if (_strcmp(command[0], "exit") != 0)
				shell_exit(command);
			else if (_strcmp(command[0], "cd") != 0)
				change_dir(command[1]);
			else
				create_child(command, av[0], env, cycles);
		}
		fflush(stdin);
		buff = NULL, size = 0;
	}
	if (line == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * loop - runs the prompt loop
 */

void loop(void)
{
	if (isatty(STDIN_FILENO))
		_puts("$ ");
}

/**
 * _EOF - handles the EOF clause
 * @buff: pointer to input string
 * Return: Nil
 */

void _EOF(char *buff)
{
	if (buff)
	{
		free(buff);
		buff = NULL;
	}

	if (isatty(STDIN_FILENO))
		_puts("\n");
	free(buff);
	exit(EXIT_SUCCESS);
}

/**
 * handle - A function to handle Ctr + C signal.
 * @signals: The signal to handle.
 * Return: Nothing.
 */
void handle(int signals)
{
	(void)signals;
	_puts("\n$ ");
}

/**
 * shell_exit - Exits the shell
 * @command: pointer to token
 * Return: Nil
 */
void shell_exit(char **command)
{
	int status = 0;

	if (command[1] == NULL)
	{
		free_dp(command);
		exit(EXIT_SUCCESS);
	}

	status = _atoi(command[1]);
	free_dp(command);
	exit(status);
}
