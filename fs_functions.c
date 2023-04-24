#include "main.h"
/**
 * get_c - gets the string corresponding to the value of c format specifier
 * @format: format string of c conversion specifier
 * @i: location of c in @format
 * @arg: value of c
 *
 * Return: value of c as a string
 */
char *get_c(const char *format, int i, int arg)
{
	char c = arg;
	char *p = malloc(sizeof(char) + 1);

	(void) format;
	(void) i;
	if (p == NULL)
	{
		return (NULL);
	}
	_strncpy(p, &c, 1);
	_strncpy(p + 1, "\0", 1);
	return (p);
}
/**
 * get_s - gets the string corresponding to the value of s format specifier
 * @format: format string of s conversion specifier
 * @i: location of s in @format
 * @arg: value of s
 *
 * Return: value of s as a string
 */
char *get_s(const char *format, int i, char *arg)
{
	char *p = malloc(_strlen(arg) + 1);

	(void) format;
	(void) i;
	if (p == NULL)
	{
		return (NULL);
	}
	_strcpy(p, arg);
	return (p);
}
/**
 * get_esc - escape conversion specifier for @arg
 * @format: format string of s conversion specifier
 * @i: location of @arg in @format
 * @arg: fs to be escaped
 *
 * Return: value of @arg as a string
 */
char *get_esc(const char *format, int i, char arg)
{
	char *p = malloc(sizeof(arg) + 1);

	(void) format;
	(void) i;
	if (p == NULL)
	{
		return (NULL);
	}
	_strncpy(p, &arg, 1);
	_strncpy(p + 1, "\0", 1);
	return (p);
}
