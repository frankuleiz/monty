#include "monty.h"
/**
 * _isdigit - checks if is digit or not
 * @str: character passed in
 * Return: 1(is digit), 0(is not digit)
 */
int _isdigit(char *str)
{
	int i = 0;

	if (str[i] == '-')
	{
		i++;
	}
	while (str[i] != '\0')
	{
		if (!isdigit(str[i]))
		{
			return (1);
		}
		i++;
	}
	return (0);
}
