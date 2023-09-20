#include "shell.h"

/**
 * handle_builtin - Handles builtin command
 * @cmd: Parsed command
 * @status: previous execution status
 * Return: -1 Fail or 0 Success
 */

int handle_builtin(char **cmd, int status)
{
	int i = 0;
	buil_t builtins[] = {
		{"cd", change_dir},
		{"env", dis_env},
		{"echo", echo_var},
		{NULL, NULL}
	};

	while ((builtins + i)->command)
	{
		if (_strcmp(cmd[0], (builtins + i)->command) == 0)
			return ((builtins + i)->fun(cmd, status));
		i++;
	}
	return (-1);
}
/**
 * check_cmd - Excute external shell comand
 *
 * @cmd: Parsed Command
 * @input: User input
 * @c: Shell executions counter
 * @argv: array of pointers (contains program Name)
 * Return: 1 (Case Command Null) -1 (Wrong Command) 0 (Command Excuted)
 */
int check_cmd(char **cmd, char *input, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
		{
			path_cmd(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
/**
 * handle_signal - Handle ^C
 * @sig:Captured Signal
 * Return: Void
 */
void handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		PRINTER("\n#cisfun$ ");
	}
}
