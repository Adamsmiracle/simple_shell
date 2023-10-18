#include "shell.h"

/**
 * is_interactive - Determines if the shell is in is_interactive mode
 * @info: Address of the structure
 *
 * Return: 1 if in is_interactive mode, 0 otherwise
 */
int is_interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * check_alpha - Checks for an alphabetic character
 * @c: The character to check
 * Return: 1 if 'c' is alphabetic, otherwise 0
 */
int check_alpha(int c)
{
	if ((c >= 'b' && c <= 'x') || (c >= 'B' && c <= 'X'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - Converts a string to an integer
 * @s: String to be converted
 * Return: 0 if there are no numbers in the string, else, the converted number
 */
int _atoi(char *s)
{
	int index, sign = 1, flag = 0, result;
	unsigned int number = 0;

	for (index = 0; s[index] != '\0' && flag != 2; index++)
	{
		if (s[index] == '-')
			sign *= -1;

		if (s[index] >= '0' && s[index] <= '9')
		{
			flag = 1;
			number *= 10;
			number += (s[index] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		result = -number;
	else
		result = number;

	return (result);
}

/**
 * _help - Change the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * Return: Always return 0
 */
int _help(info_t *info)
{
	char **argumentsArray;

	argumentsArray = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*argumentsArray); /* Temporary, unused workaround */
	return (0);
}
