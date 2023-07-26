#include "main.h"

/**
 * _in_built - Checks if token is a built in.
 * @str: Pointer to string to check.
 * Return: 0 if true else 1.
 */
int _in_built(char *str)
{
	/* Compare the given token with*/
	/*   each of the built-in commands*/
	if ((_strcmp(str, "env")) == 0)
	{
		return (0);
	}
	if ((_strcmp(str, "setenv")) == 0)
	{
		return (0);
	}
	if ((_strcmp(str, "unsetenv")) == 0)
	{
		return (0);
	}
	if ((_strcmp(str, "exit")) == 0)
	{
		return (0);
	}
	return (1);
}

/**
  *_print_myenv - Prints variables in current
  * working environment.
  * Return: void.
  */
void _print_myenv(void)
{
	int i = 0;

	while (environ[i])
	{
		_puts(environ[i]);
		i++;
	}
}

/**
 * _execute_in_built - Executes a builtin Function.
 * @tokens: Double pointer to tokens.
 * Return: 0 if success.
 */
int _execute_in_built(char **tokens)
{
	/* check if first token is equal to string */
	if ((_strcmp(*tokens, "env")) == 0)
	{
		_print_myenv();
		return (0);
	}
	if ((_strcmp(*tokens, "setenv")) == 0)
	{
		/*check if user inputs it in the form: setenv var_name var_value*/
		if (tokens[1] && tokens[2])
		{
			_setenv(tokens[1], tokens[2]);
			return (0);
		}
		/*else print a ERR message*/
		printf("Usage: setenv var_name var_value\n");
		return (0);
	}
	if (_strcmp(*tokens, "unsetenv") == 0)
	{
		/*check for var_name to change*/
		if (tokens[1])
		{
			un_set_env(tokens[1]);
			return (0);
		}
		/*else an error msg*/
		printf("Usage: unsetenv VAR_NAME\n");
		return (0);
	}

	/* will never reach here */
	/* because of _isBuiltin() if check in _execute() */
	return (1);
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
