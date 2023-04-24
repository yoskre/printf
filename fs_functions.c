#include "main.h"
/**
 * int_digits - number of digits in an integer
 * @i: integer
 *
 * Return: number of digits in @i
 */
int int_digits(int i)
{
	int count = 0;

	if (i < 0)
		count++;
	while (i != 0) 
	{
		i /= 10;
		count++;
	}
	return (count);
}
char* int_to_str(int num) 
{
	int digit_count = int_digits(num);
	char* str = (char*) malloc(sizeof(char) * (digit_count + 1));
	int is_negative = 0;

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	for (int i = digit_count - 1; i >= 0; i--)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
	}
	if (is_negative)
	{
		str[0] = '-';
	}
	str[digit_count] = '\0';
	return (str);
}
/**
 * get_int - gets the string corresponding to the value of c format specifier
 * @format: format string of c conversion specifier
 * @i: location of c in @format
 * @arg: value of c
 *
 * Return: value of c as a string
 */
char *get_int(const char *format, int i, int arg)
{
	char *p;

	if (format[i - 1] == 'c')
	{
		char c = arg;

		p = malloc(sizeof(char) + 1);
		(void) format;
		(void) i;
		if (p == NULL)
			return (NULL);
		_strncpy(p, &c, 1);
		_strncpy(p + 1, "\0", 1);
	}
	else
		p = int_to_str(arg);
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
	char *p;

	if (!arg)
		return (NULL);
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
