#include "shell.h"

/**
 * _eputs - prints a string input
 * @str: the string to be printed
 * Return: Nothing
 */
void _eputs(char *str)
{
	int j = 0;

	if (!str)
		return;
	while (str[j] != '\0')
	{
		_eputchar(str[j]);
		j++;
	}
}

/**
 * _eputchar - writes the character a to stderr
 * @a: The character to print
 * Return: On success 1
 * On error, -1 is returned and errno is set appropriately.
 */
int _eputchar(char a)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (a == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(2, buf, j);
		j = 0;
	}
	if (a != BUF_FLUSH)
		buf[j++] = a;
	return (1);
}

/**
 * _putfd - writes the character a to given df
 * @a: The character to print
 * @df: The filedescriptor to write to
 * Return: On success 1
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char a, int df)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (a == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(df, buf, j);
		j = 0;
	}
	if (a != BUF_FLUSH)
		buf[j++] = a;
	return (1);
}

/**
 * _putsfd - prints an input string
 * @str: the string to be printed
 * @df: the filedescriptor to write to
 * Return: the number of chars put
 */
int _putsfd(char *str, int df)
{
	int j = 0;

	if (!str)
		return (0);
	while (*str)
	{
		j += _putfd(*str++, df);
	}
	return (j);
}

