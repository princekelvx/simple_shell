#include "main.h"

/**
 * create_child - creates a subprocess
 * @command: pointer to tokenized command
 * @name: pointer to shell name
 * @env: pointer to environment variables
 * @cycles: number of execution cycles
 * Return: Nil
 */

void create_child(char **command, char *name, char **env, int cycles)
{
	int pid = 0, status = 0, wait_error = 0;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: ");
		free_exit(command);
	}
	else if (pid == 0)
	{
		execute(command, name, env, cycles);
		free_dp(command);
	}
	else
	{
		wait_error = waitpid(pid, &status, 0);
		if (wait_error < 0)
			free_exit(command);
		free_dp(command);
	}
}

/**
 * change_dir - changes the working directory
 * @path: the new current working directory
 * Return: 0 on Success, -1 otherwise
 */

int change_dir(const char *path)
{
	char *buf = NULL;
	size_t size = 1024;

	if (path == NULL)
		path = getcwd(buf, size);
	if (chdir(path) == -1)
	{
		perror(path);
		return (98);
	}
	return (1);
}
