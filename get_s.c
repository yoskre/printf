#include <string.h>
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

	(void) format;
	(void) i;
	if (*arg == '\0' || strcmp(arg,"") == 0)
	{
		p = malloc(sizeof(char));
		if (p == NULL)
			return (NULL);
		strncpy(p, "\0", 1);
	}
	if (arg == NULL)
	{
		p = malloc(sizeof(char) * 7);
		if (p == NULL)
			return (NULL);
		strncpy(p, "(null)\0", 7);
	}
	else
	{
		p = malloc(_strlen(arg) + 1);
		if (p == NULL)
			return (NULL);
		strncpy(p, arg, strlen(arg) + 1);
	}
	return (p);
}
