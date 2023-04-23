#include <stdarg.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
/**
 * _printf - prints @format
 * @format: string
 * @...: conversion specifier values
 *
 * Description: printf prints @string to standard output.
 * In case @string contains conversion specifiers(1),
 * printf will fetch the values for each one from the arguments
 * following @format.
 *
 * (1): Conversion specifiers are special sequences introduced
 * by the character %.
 * Conversions supported are:
 *	c: character.
 *	s: string.
 *
 * Return: returns number of characters printed, excluding
 * the null character at the end of @format. If there is
 * an error the function returns -1.
 */
int _printf(const char *format, ...)
{
	/* Variadic variable */
	va_list arg;
	/* Number of characters printed */
	int pcounter = 0;
	/* For now value should be set to -1 if there is an error */
	int err;
	/* Value of f should be set to the character to be printed */
	char *f;
	/* Temporary counter */
	size_t i;

	va_start(arg, format);
	for (i = 0; i < strlen(format); i++)
	{
		f = malloc(sizeof(format[i] + 1));
		if (f == NULL)
			return (err = -1);
		strncpy(f, &(format[i]), 1);
		strncpy(f + 1, "\0", 1);
		if (*f == '%')
		{
			/* ------------ */
			int j = get_fs(f);

			if (j  < 0)
				return (err = -1);
			/* ------------- */
		}
		if (write(STDIN_FILENO, f, strlen(f)) < 0)
			return (err = -1);
		pcounter += strlen(f);
		free(f);
	}
	return (pcounter);
}
