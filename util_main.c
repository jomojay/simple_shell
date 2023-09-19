#include "shell.h"

/**
 * parse_cmd - Parse Line Of Input
 * @input:User Input To Parse
 * Return: Array Of Char (Parsed):Simple Shell
 */
char **parse_cmd(char *input)
{
	char **toks, *tok;
	int i, buffsize = BUFSIZE;

	if (input == NULL)
		return (NULL);
	toks = malloc(sizeof(char *) * buffsize);
	if (!toks)
	{
		perror("hsh");
		return (NULL);
	}

	tok = _strtok(input, "\n ");
	for (i = 0; tok; i++)
	{
		toks[i] = tok;
		tok = _strtok(NULL, "\n ");
	}
	toks[i] = NULL;

	return (toks);
}
/**
* prompt - Display Shell Prompt
*/
void prompt(void)
{
	PRINTER("#cisfun$ ");
}
/**
 * check_builtin - check builtin
 *
 * @cmd:command to check
 * Return: 0 Succes -1 Fail
 */
int check_builtin(char **cmd)
{
	int i = 0;

	bul_t fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	if (*cmd == NULL)
	{
		return (-1);
	}

	while ((fun + i)->command)
	{
		if (_strcmp(cmd[0], (fun + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}
/**
 * creat_env - Creat Array of Enviroment Variable
 * @env: Array of Enviroment Variable
 * Return: Void
 */
void creat_env(char **env)
{
	int i;

	for (i = 0; environ[i]; i++)
		env[i] = _strdup(environ[i]);
	env[i] = NULL;
}
