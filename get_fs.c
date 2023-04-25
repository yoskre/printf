#include "main.h"
/**
 * get_fs - get location of the format specifier
 * @format: adress of fs in format string
 *
 * Return: location of fs in @format
 */
int get_fs(const char *format)
{
	char fs[] = {'c', 's', '%',
	       'd', 'i'};
	/* s and fs lengths */
	int lfs = sizeof(fs) / sizeof(char);
	/* temp counter variables */
	int i = 1;
	int j;

	while (format[i])
	{
		if (format[i] != ' ')
			break;
		i++;
	}
	while (format[i])
	{
		if (format[i] == ' ')
			break;
		for (j = 0; j < lfs; j++)
		{
			if (format[i] == fs[j])
				return (i + 1);
		}
		i++;
	}
	return (-1);
}
