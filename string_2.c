#include "shell.h"

/**
 * _strcmp - Compare two strings
 * @s1: pointer to string 1
 * @s2: pointer to string 2
 * Return: 0 (SUCCESS) or the difference(FAILED))
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
/**
 * _strncpy - copies string from src to dest
 * @dest: pointer to destination
 * @src: pointer to source string
 * @n: number of characters to copy from 0th index
 *
 * Return: Return a pointer to a copy of src  string via dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while ((n > i) && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (n > i)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/**
 * _strlen -breturns the length of a given string
 * @s: pointer to the string
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}
