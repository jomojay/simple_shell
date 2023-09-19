#include "shell.h"

/**
 * echo_var - Excute echo variable cases
 * @status: Status of last command
 * @cmd: command array
 * Return: Always 0 Or Excute Normal Echo
 */
int echo_var(char **cmd, int status)
{
	char *path;
	size_t p_pid = getppid();
	int cmd_case = -1;

	if (cmd[1] != NULL)
	{
		if (_strncmp(cmd[1], "$?", 2) == 0)
			cmd_case = 0;
		else if (_strncmp(cmd[1], "$$", 2) == 0)
			cmd_case = 1;
		else if (_strncmp(cmd[1], "$PATH", 5) == 0)
			cmd_case = 2;
	}
	switch (cmd_case)
	{
		case 0:
			print_int(status);
			PRINTER("\n");
			break;
		case 1:
			print_num(p_pid);
			PRINTER("\n");
			break;
		case 2:
			path = _getenv("PATH");
			PRINTER(path);
			PRINTER("\n");
			free(path);
			break;
		default:
			return (_echo(cmd));
	}

	return (1);
}
/**
 * _echo - custom echo
 * @cmd: Parsed Command
 * Return: 0 Succes -1 Fail
 */
int _echo(char **cmd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		if (execve("/bin/echo", cmd, environ) == -1)
			return (-1);
		exit(EXIT_FAILURE);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
