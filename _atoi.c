#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 * Return: 1 if interactive mode and 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is delimeter
 * @h: the char to check
 * @delim: the delimeter is string
 * Return: 0 if false and 1 if true
 */
int is_delim(char h, char *delim)
{
	while (*delim)
		if (*delim++ == h)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * Return: 1 if c is alphabetic and 0 otherwise
 * @j: the character to input
 */

int _isalpha(int j)
{
	if ((j >= 'a' && j <= 'z') || (j >= 'A' && j <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - transform a string to an integer
 * @m: the string to be transformed
 * Return: 0 if no numbers in string and transformed number otherwise
 */

int _atoi(char *m)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; m[i] != '\0' && flag != 2; i++)
	{
		if (m[i] == '-')
			sign *= -1;

		if (m[i] >= '0' && m[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (m[i] - '0');
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

