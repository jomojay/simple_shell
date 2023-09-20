#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>

/**##### MACROS ######*/
#define BUFSIZE 1024
#define PRINTER(c) (write(STDOUT_FILENO, c, _strlen(c)))

/**
* struct bulltin - contain bultin to handle and function to excute
* @command:pointer to char
* @fun:fun to excute when bultin true
*/
typedef struct bulltin
{
	char *command;
	int (*fun)(char **line, int er);
} bul_t;

extern char **environ;

/** ### String functions ### */
char *_strtok(char *str, const char *tok);
unsigned int delim_check(char c, const char *str);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _putchar(char c);
int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void array_rev(char *arr, int len);
int int_len(int num);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);

/** ### Iput Functions ### */
void prompt(void);
void handle_signal(int sig);
char *_getline(void);

/** ### Command manipulation ### */
int path_cmd(char **line);
char *_getenv(char *name);
char **parse_cmd(char *cmd);
int handle_builtin(char **cmd, int status);
void read_file(char *filename, char **argv);
char *build_ap(char *token, char *value);
int check_builtin(char **cmd);
void creat_env(char **env);
int check_cmd(char **tokens, char *line, int count, char **argv);
void exec_file(char *line, int counter, FILE *fd, char **argv);
void file_exit(char **cmd, char *line, FILE *fd);
/** ### Printers ### */
void print_num(unsigned int n);
void print_int(int n);
int _putchar(char c);

/** ### Memory functions ### */

void free_env(char **env);
void *fill_array(void *ptr, int value, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **input, char *line);

/** ### Builtins ### */
void hashtag_check(char *buff);
void exit_sh(char **cmd, char *input, char **argv, int c);
int dis_env(char **cmd, int st);
int change_dir(char **cmd, int status);
int echo_var(char **cmd, int status);
int _echo(char **cmd);

/** ### Error Printer ### */
void print_error(char *line, int c, char **argv);
void _prerror(char **argv, int c, char **cmd);

#endif /* _SHELL_H */
