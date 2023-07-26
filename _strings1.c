#include "main.h"

/**
 * _strcat - Concatenates two strings.
 * @dest: Pointer to string to be conatenated upon.
 * @src: Pointer to string to append to dest.
 * Return: Pointer to dest.
 */
char *_strcat(char *dest, char *src)
{
	char *destAddress;
	int destLen;

	destAddress = dest;
	destLen = _strlen(dest);
	destAddress = destAddress + destLen;
	while (*src != '\0')
	{
		*destAddress = *src;
		src++;
		destAddress++;
	}
	*destAddress = '\0';

	return (dest);
}

/**
 * _strtotokens - splits a string into words.
 * @str: Pointer to string.
 * Return: Pointer to array of words.
 */
char **_strtotokens(char *str)
{
	int i = 0;
	const char delimeter[] = " \t\n";
	int space = _check_white_space(str);
	char **tokens = malloc(sizeof(char *) * (space + 1));
	char *token;

	if (!tokens)
	{
		free(tokens);
		fprintf(stderr, "sh: allocation error\n");
		exit(1);
	}

	token = strtok(str, delimeter);

	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, delimeter);
		i++;
	}
	tokens[i] =  NULL;

	return (tokens);
}

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
