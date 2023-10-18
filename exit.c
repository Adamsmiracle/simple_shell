#include "shell.h"

/**
 * _strncpy - Copy a string with a specified length
 * @dest: The destination string to be copied to
 * @src: The source string
 * @n: The maximum number of characters to be copied
 * Return: The concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}


/* 8888888888888888888888888888888888888888888888888 */

/**
 * print_decimal - Print a decimal (integer) number (base 10)
 * @number: The input number
 * @fd: The file descriptor to write to
 * Return: Number of characters printed
 */
int print_decimal(int number, int fd)
{
	int (*putCharFunction)(char) = _putchar;
	int i, count = 0;
	unsigned int absoluteValue, current;

	if (fd == STDERR_FILENO)
		putCharFunction = _err_putchar;
	if (number < 0)
	{
		absoluteValue = -number;
		putCharFunction('-');
		count++;
	}
	else
		absoluteValue = number;
	current = absoluteValue;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (absoluteValue / i)
		{
			putCharFunction('0' + current / i);
			count++;
		}
		current %= i;
	}
	putCharFunction('0' + current);
	count++;

	return (count);
}

/**
 * convert_num_to_str - Convert a number to a string in a specified base
 * @num: The number
 * @base: The base
 * @flags: Argument flags
 * Return: A string representation of the number
 */
char *convert_num_to_str(long int num, int base, int flags)
{
	/* Function to convert a number to a string representation in a given base */
}

/**
 * remove_comments - Replace the first instance of '#' with '\0' in a string
 * @buf: Address of the string to modify
 * Return: Always 0
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
