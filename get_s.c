#include "main.h"
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
	char *p;

	if (!arg)
		return ("(null)");
	(void) format;
	(void) i;
	p = malloc(_strlen(arg) + 1);
	if (p == NULL)
	{
		return (NULL);
	}
	_strcpy(p, arg);
	return (p);
}
