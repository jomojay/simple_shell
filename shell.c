#include "shell.h"

/**
 * main - simple shell
 * @argc: argument counter
 * @argv: argument vector
 * Return: exit status
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	char *input, **cmd;
	int status = 0, count = 0, cycle = 1;

	if (argv[1] != NULL)
		read_file(argv[1], argv);
	signal(SIGINT, handle_signal);
	while (cycle)
	{
		count++;
		if (isatty(STDIN_FILENO))
			prompt();
		input = _getline();
		if (input[0] == '\0')
			continue;
		cmd = parse_cmd(input);
		if (_strcmp(cmd[0], "exit") == 0)
		{
			exit_sh(cmd, input, argv, count);
		}
		else if (check_builtin(cmd) == 0)
		{
			status = handle_builtin(cmd, status);
			free_all(cmd, input);
			continue;
		}
		else
			status = check_cmd(cmd, input, count, argv);
		free_all(cmd, input);
	}
	return (cycle);
}
