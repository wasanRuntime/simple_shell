#include "main.h"

/**
 * prompt - Print prompt.
 * Return: Void.
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "#cisfun$ ", 9);
	}
}

/**
 * _checklen - Returns length of a string.
 * @s: Pointer to string.
 * Return: Length of s.
 */
int _checklen(char *s)
{
	int index;

	index = 0;
	while (s[index] != '\0')
	{
		index++;
	}
	return (index);
}
