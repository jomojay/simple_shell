#include "shell.h"

/**
 * read_file - Read Command From File
 * @filename:Filename
 * @argv:Program Name
 * Return: -1(fail) or  0(success)
 */
void read_file(char *filename, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int count = 0;

	fp = fopen(filename, "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);
	while ((getline(&line, &len, fp)) != -1)
	{
		count++;
		exec_file(line, count, fp, argv);

	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}
/**
 * exec_file - PARSE Check Command Fork Wait Excute in Line of File
 * @line: Line From A File
 * @count:Error Counter
 * @fp:File Descriptor
 * @argv:Program Name
 * Return : Nothing
 */
void exec_file(char *line, int count, FILE *fp, char **argv)
{
	char **cmd;
	int status = 0;

	cmd = parse_cmd(line);

	if (_strncmp(cmd[0], "exit", 4) == 0)
		file_exit(cmd, line, fp);
	else if (check_builtin(cmd) == 0)
	{
		status = handle_builtin(cmd, status);
		free(cmd);
	}
	else
	{
		status = check_cmd(cmd, line, count, argv);
		free(cmd);
	}
}
/**
 * file_exit - Exit Shell (Case Of File)
 * @line: Line From A File
 * @cmd: Parsed Command
 * @fd:File Descriptor
 * Return : Nothing
 */
void file_exit(char **cmd, char *line, FILE *fd)
{
	int status, i = 0;

	if (cmd[1] == NULL)
	{
		free(line);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) < 0)
		{
			perror("illegal number");
		}
	}
	status = _atoi(cmd[1]);
	free(line);
	free(cmd);
	fclose(fd);
	exit(status);
}
