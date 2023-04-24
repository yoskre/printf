#include "main.h"
/**
 * _strcpy - copy a string
 * @s1: the destination string
 * @s2: the source string
 *
 * Return: a pointer to the destination string
 */
char *_strcpy(char *s1, const char *s2)
{
	char *ptr = s1;

	while (*s2 != '\0')
	{
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = '\0';
	return (ptr);
}
/**
 * _strncpy - copy a string with a specified maximum length
 * @s1: the destination string
 * @s2: the source string
 * @n: the maximum number of characters to copy
 *
 * Return: a pointer to the destination string
 */
char *_strncpy(char *s1, const char *s2, int n)
{
	char *ptr = s1;

	while (n > 0 && *s2 != '\0')
	{
		*s1 = *s2;
		s1++;
		s2++;
		n--;
	}
	while (n > 0)
	{
		*s1 = '\0';
		s1++;
		n--;
	}
	return (ptr);
}
/**
 * _strlen - get the length of a string
 * @s: the string to get the length of
 *
 * Return: the length of the string
 */
int _strlen(const char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
