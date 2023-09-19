#include "shell.h"

/**
* _getline - Read user input from STDIN
* Return: Returns line input(buff)
*/
char *_getline(void)
{
	int buff_size = BUFSIZE, line_c, i, c = 0;
	char *buff = malloc(buff_size);

	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}
	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		line_c = read(STDIN_FILENO, &c, 1);
		if (line_c == 0)
		{
			free(buff);
			exit(EXIT_SUCCESS);
		}
		buff[i] = c;
		if (buff[0] == '\n')
		{
			free(buff);
			return ("\0");
		}
		if (i >= buff_size)
		{
			buff = _realloc(buff, buff_size, buff_size + 1);
			if (buff == NULL)
				return (NULL);
		}
	}
	buff[i] = '\0';
	hashtag_check(buff);
	return (buff);
}
/**
* hashtag_check - removes everything after #
* @buff: input
* Return:void
*/
void hashtag_check(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] == '#')
		{
			buff[i] = '\0';
			break;
		}
	}
}
