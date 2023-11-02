#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>

/**
 * main - program entry point
 *
 * Return: Always 0
 */

int main(void)
{
	int i, status;
	pid_t child_pid;
	char *args[] = {"ls", "-l", "/tmp", NULL};

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			if (execve("/bin/ls", args, NULL) == -1)
				perror("execve error:");
			else if (child_pid < 0)
				perror("fork error:");
			else
				wait(&status);
		}
	}
	return (0);
}
