#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER 256

/**
 * main - program entry point
 *
 * Return: Always 0
 */

int main(void)
{
	pid_t child_pid;
	char buffer[BUFFER], *prompt = "#cisfun$ ";
	char *argv[2];
	int status;

	while (1)
	{
		/* display a prompt */
		write(STDOUT_FILENO, prompt, strlen(prompt));
		/* read user input from stdin */
		if (fgets(buffer, sizeof(buffer), stdin) == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		/* remove the newline char at the end of input */
		buffer[strcspn(buffer, "\n")] = '\0';

		/* initialise child process */
		child_pid = fork();
		if (child_pid == -1)
			perror("fork");
		else if (child_pid == 0)
		{
			argv[0] = buffer;
			argv[1] = NULL;
			/* child process */
			if (execve(buffer, argv, NULL) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		       	/* parent process wait for child to terminate */
			wait(&status);
	}
	return (0);
}
