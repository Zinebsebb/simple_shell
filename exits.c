#include "shell.h"

/**
 *_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@m: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int m)
{
	int k, l;
	char *a = dest;

	k = 0;
	while (src[k] != '\0' && k < m - 1)
	{
		dest[k] = src[k];
		k++;
	}
	if (k < m)
	{
		l = k;
		while (l < m)
		{
			dest[l] = '\0';
			l++;
		}
	}
	return (a);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@m: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int m)
{
	int k, l;
	char *a = dest;

	k = 0;
	l = 0;
	while (dest[k] != '\0')
		k++;
	while (src[l] != '\0' && l < m)
	{
		dest[k] = src[l];
		k++;
		l++;
	}
	if (l < m)
		dest[k] = '\0';
	return (a);
}

/**
 **_strchr - locates a character in a string
 *@a: the string to be parsed
 *@b: the character to look for
 *Return: (a) a pointer to the memory area a
 */
char *_strchr(char *a, char b)
{
	do {
		if (*a == b)
			return (a);
	} while (*a++ != '\0');

	return (NULL);
}

