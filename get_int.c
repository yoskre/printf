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
/**
 * int_to_str - convert int to str
 * @num: number
 *
 * Return: @num in the form of a string
 */
char *int_to_str(int num)
{
	int digit_count = int_digits(num);
	char *str = malloc(sizeof(char) * (digit_count + 1));
	int is_negative = 0;
	int i;

	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	for (i = digit_count - 1; i >= 0; i--)
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
 * decimal_to_binary_str - convert decimal integer to binary string
 * @decimal: decimal integer to convert
 *
 * Return: pointer to binary string
 */
char *decimal_to_binary_str(int decimal)
{
	int i, remainder, quotient;
	char *binary_str;
	int binary_str_len = 0;
	/* find the length of the binary string */
	quotient = decimal;
	do {
	binary_str_len++;
	quotient /= 2;
	} while (quotient > 0);
	/* allocate memory for the binary string */
	binary_str = malloc(sizeof(char) * (binary_str_len + 1));
	if (binary_str == NULL)
		return (NULL);
	/* convert the decimal to binary and store in string */
	for (i = binary_str_len - 1; i >= 0; i--)
	{
		remainder = decimal % 2;
		decimal /= 2;
		binary_str[i] = remainder + '0';
	}
	binary_str[binary_str_len] = '\0';
	return (binary_str);
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

	if (format[i] == 'c')
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
	else if (format[i] == 'b')
		decimal_to_binary_str(arg);
	else
		p = int_to_str(arg);
	return (p);
}
