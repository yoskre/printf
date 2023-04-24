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
	va_list arg;
	int pcounter = 0, err, i = 0;
	char *f;

	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			int j;

			j = get_fs(&format[i]);
			if (j  < 0)
				return (err = -1);
			if (format[i + j - 1] == 'c')
				f = get_c(&format[i], j, va_arg(arg, int));
			else if (format[i + j - 1] == 's')
				f = get_s(&format[i], j, va_arg(arg, char *));
			else if (format[i + j - 1] == '%')
				f = get_esc(&format[i], j, format[i + j - 1]);
			if (f == NULL)
				return (err = -1);
			write(STDIN_FILENO, f, strlen(f));
			i += j - 1;
			pcounter += strlen(f);
			free(f);
		}
		else
		{
			write(STDIN_FILENO, &format[i], 1);
			pcounter++;
		}
		i++;
	}
	return (pcounter);
}
