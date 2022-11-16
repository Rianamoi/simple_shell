#include "shell.h"
int lsh_eof(char **args);
/**
 * lsh_eof - handle end of file
 * @args: arguements
 * Return: 0
 */
int lsh_eof(char **args)
{
	(void)args;
	return (0);
}
/**
 * _getline_command -  GEts inputs
 *   * Return: The input.
 */
char *_getline_command(void)
{
	char *lineptr = NULL;
	size_t charter_user = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	if (getline(&lineptr, &charter_user, stdin) == -1)
	{
		free(lineptr);
		return (NULL);
	}

	return (lineptr);
}
