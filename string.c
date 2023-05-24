#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @a: the string whose length to check
 * Return: integer length of string
 */
int _strlen(char *a)
{
	int i = 0;

	if (!a)
		return (0);

	while (*a++)
		i++;
	return (i);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @a1: the first strang
 * @a2: the second strang
 * Return: negative if a1 < a2, positive if a1 > a2, zero if a1 == a2
 */
int _strcmp(char *a1, char *a2)
{
	while (*a1 && *a2)
	{
		if (*a1 != *a2)
			return (*a1 - *a2);
		a1++;
		a2++;
	}
	if (*a1 == *a2)
		return (0);
	else
		return (*a1 < *a2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

