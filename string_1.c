#include "shell.h"

/**
 * _strcpy - Copies char from source to destination
 * @dest: Destination pointer
 * @src: Source pointer
 * Return: Copy of char *
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcat - Concatenate two strings
 * @dest: sting 1
 * @src: String 2
 * Return:An updated *dest pointer
 */
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i])
	{
		i++;
	}
	if (dest[i] == '\0')
	{
		while (src[j] != '\0')
		{
			dest[i] = src[j];
			i++;
			j++;
		}
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strchr - Locate a character in a string
 * @s: String to search from
 * @c: Char to search for
 * Return: Pointer to Char* or NULL(fail)
 */
char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((s + i));
		i++;
	}
	if (s[i] == c)
		return (s + i);
	return (0);
}
/**
 * _strncmp - Compare Amount (n) Of Characters Of Two Strings.
 * @s1: A String.
 * @s2: A String.
 * @n: Amount Of Characters To Compare.
 *
 * Return: 1 If The Strings Don't Match Otherwise 0
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL)
		return (-1);
	for (i = 0; i < n && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (1);
		}
	}
	return (0);
}
/**
 * _strdup - Duplicates a string
 * @str: String pointer
 * Return: Duplicated String or (NULL)
 */
char *_strdup(char *str)
{
	size_t len, i;
	char *str2;

	len = _strlen(str);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
	{
		return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		str2[i] = str[i];
	}

	return (str2);
}
