#include "shell.h"
/**
 * delim_check - Checks if c matches any of the char in *str
 * @c: Character To Check
 * @str: String To Check
 * Return: 1 Succes, 0 Failed
 */
unsigned int delim_check(char c, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (c == str[i])
			return (1);
	}
	return (0);
}

/**
 * _strtok - Tokenize *str into token
 * @str: String
 * @delim: Delimiter
 * Return: Pointer To The Next Token Or NULL
 */
char *_strtok(char *str, const char *delim)
{
	static char *n_toks, *c_toks;
	unsigned int i;

	if (str != NULL)
		n_toks = str;
	c_toks = n_toks;
	if (c_toks == NULL)
		return (NULL);
	for (i = 0; c_toks[i] != '\0'; i++)
	{
		if (delim_check(c_toks[i], delim) == 0)
			break;
	}
	if (n_toks[i] == '\0' || n_toks[i] == '#')
	{
		n_toks = NULL;
		return (NULL);
	}
	c_toks = n_toks + i;
	n_toks = c_toks;
	for (i = 0; n_toks[i] != '\0'; i++)
	{
		if (delim_check(n_toks[i], delim) == 1)
			break;
	}
	if (n_toks[i] == '\0')
		n_toks = NULL;
	else
	{
		n_toks[i] = '\0';
		n_toks = n_toks + i + 1;
		if (*n_toks == '\0')
			n_toks = NULL;
	}
	return (c_toks);
}
