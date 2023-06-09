#include <stdarg.h>
#include <stdlib.h>
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

	if (!format)
		return (err = -1);
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			int j;

			j = get_fs(&format[i]);
			if (j  < 0)
			{
				return (pcounter);
			}
			if (format[i + j] == 'c' || format[i + j] == 'd'
				|| format[i + j] == 'i' || format[i + j] == 'b')
				f = get_int(&format[i], j, va_arg(arg, int));
			else if (format[i + j] == 's')
				f = get_s(&format[i], j, va_arg(arg, char *));
			else if (format[i + j] == '%')
				f = get_esc(&format[i], j, format[i + j]);
			if (f == NULL)
				return (pcounter);
			write(1, f, _strlen(f));
			i += j;
			pcounter += _strlen(f);
			free(f);
		}
		else
		{
			write(1, &format[i], 1);
			pcounter++;
		}
		i++;
	}
	return (pcounter);
}
