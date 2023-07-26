#include "main.h"

/**
 * _puts - prints a string, followed by a new line, to stdout.
 * @str: string to print.
 */
void _puts(char *str)
{
	unsigned long i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}

	_putchar('\n');
}

#include "main.h"

/**
 * _putchar - Writes the character c to stdout.
 * @c: The character to print.
 * Return: On success - 1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
