#include "shell.h"
/**
 * shell_loop - make a infinite loop
 * @args: array of strings with arguments
 * Return: return void
 */
void shell_loop(char **args)
{
	int promptline = 0;
	char **lineargs = NULL;
	int status = 1;
	char *line = NULL;
	size_t buffersize = 0;

	while (status)
	{
		if (isatty(STDIN_FILENO))
		{
			/* print the prompt */
			_puts("#cisfun$ ");
		}
		/* read the line from input */
		/*promptline = shell_read_line();*/
		promptline = getline(&line, &buffersize, stdin);

		if (promptline == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		/* tokenize the args from input */
		lineargs = shell_split_line(line);
		/* execute the program as the args says */
		status = shell_execute(lineargs);
		if (status == 2)
		{
			_puts((char *)args[0]);
			_puts(": ");
			_puts("1");
			_puts(": ");
			_puts(lineargs[0]);
			_puts(": ");
			_puts("not found\n");
			status = 1;
		}
		free(lineargs);
	}
	free(line);
}
