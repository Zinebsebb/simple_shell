#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * Return: 1 if interactive mode and 0 otherwise
 * @info: struct address
 */

int interactive(info_t *info)
{
	int isInteractive = (isatty(STDIN_FILENO) && info->readfd <= 2);

	return (isInteractive);
}
/**
 * is_delim - checks if character is delimeter
 * @c: the char to check
 * Return: 0 if false and 1 if true
 * @delim: the delimeter string
 */

int is_delim(char c, char *delim)
{
	int isDelimiter = 0;

	while (*delim != '\0')
	{
		if (*delim == c)
		{
			isDelimiter = 1;
			break;
		}
		delim++;
	}
	return (isDelimiter);
}
/**
 * _isalpha - checks for alphabetic character
 * @c: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	int isAlphabetic = 0;

	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		isAlphabetic = 1;
	return (isAlphabetic);
}
/**
 * _atoi - transform a string to an integer
 * Return: 0 if no numbers in strin and transformed number otherwise
 * @s: the string to be transformed
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
