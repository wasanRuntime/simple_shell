#include "main.h"

/**
 *ctrlc - Control C handler.
 *@signum: The signal number received.
 *
 *Return: Void.
 */
void ctrlc(int signum)
{
	(void)signum;

	exit(0);
	write(STDOUT_FILENO, "\n#cisfun$ ", 10);
}

/**
 * _exit_simple_shell - Exits the shell
 * and frees memory.
 * @tokens: Double pointer to words split from line.
 * @line: Pointer to string got using getLine().
 * Return: void.
 */
void _exit_simple_shell(char **tokens, char *line)
{
	int status;

	if (tokens[1] != NULL)
	{
		status = atoi(tokens[1]);
		if (status >= 0)
		{
			free(line);
			free(tokens);
			exit(status);
		}
		write(STDERR_FILENO, "Exit: illegal exit status: ", 28);
		write(STDERR_FILENO, tokens[1], 1);
		write(STDERR_FILENO, "\n", 1);
	}
	else
	{
		free(line);
		free(tokens);
		exit(0);
	}
}
