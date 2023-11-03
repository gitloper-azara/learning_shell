#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/* #include "_getenv.c" */

extern char **environ;

/**
 * main - prints each directory in the PATH environment variable
 *
 * Return: Always 0.
 */

int main(int ac, char **av)
{
	char *path;
	char *token;
	/* unsigned int i; */
	(void)ac;
	(void)av;

	path = getenv("PATH");
	token = strtok(path, ":");
	while (token)
	{
	        printf("%s\n", token);
		token = strtok(NULL, ":");
	}
	return (0);
}
