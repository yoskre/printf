#include "main.h"
/**
 * get_fs - get location of the format specifier
 * @format: adress of fs in format string
 *
 * Return: location of fs in @format
 */
int get_fs(const char *format)
{
	char fs[] = {'c', 's', '%'};
	/* s and fs lengths */
	int lfs = sizeof(fs) / sizeof(char);
	int ls = _strlen(format);
	/* temp counter variables */
	int i;
	int j;

	for (i = 0; i < ls; i++)
		if (format[i] != ' ')
			break;
	for (; i < ls; i++)
	{
		if (format[i] == ' ')
			break;
		for (j = 0; j < lfs; j++)
		{
			if (format[i] == fs[j])
				return (i + 2);
		}
	}
	return (-1);
}
