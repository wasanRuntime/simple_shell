#include "main.h"

/**
 *_strlen -  calculates the length of a null-terminated string
 *@s: stores the string entered
 *Return: integer(length of the string)
 **/
int _strlen(char *s)
{
	char *ptr;

	ptr = s;
	while (*ptr != '\0')
	{
		ptr++;
	}
	return (ptr - s);
}

/**
 * _check_white_space -count the number of white spaces
 *      in a null-terminated string
 * @s: Pointer to string to check.
 * Return: integer.
 */
unsigned int _check_white_space(char *s)
{
	unsigned int count = 0;

	while (*s != '\0')
	{
		if (*s == ' ' || *s == '\t' || *s == '\n')
			count++;
		s++;
	}
	return (count);
}
