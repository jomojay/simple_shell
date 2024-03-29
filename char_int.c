#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * print_num - Recursively print positive numbers
 * @n: Unisigned integer to be printed
 *
 * Return: Void
 */
void print_num(unsigned int n)
{
	unsigned int x = n;

	if ((x / 10) > 0)
		print_num(x / 10);
	_putchar(x % 10 + '0');
}
/**
 * print_int - Print signed integer
 * @n: integer to be printed
 * Return: void
 */
void print_int(int n)
{
	unsigned int x = n;

	if (n < 0)
	{
		_putchar('-');
		x = -x;
	}
	if ((x / 10) > 0)
		print_num(x / 10);
	_putchar(x % 10 + '0');
}
