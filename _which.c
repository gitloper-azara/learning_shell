#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER 1024

int main(int argc, char *argv[])
{
	char *path, *token;
	char filepath[BUFFER];
	size_t i, j;
	struct stat st;

	if (argc < 2)
	{
		printf("Usage: %s filename ...\n", argv[0]);
		return (1);
	}

	path = getenv("PATH");
	if (!path)
	{
		printf("Could not get PATH environment variable.\n");
		exit(1);
	}
	/* split PATH into a list of directories */
	token = strtok(path, ":");
	while (token)
	{
		for (i = 0; i < sizeof(filepath); i++)
			filepath[i] = '\0';
		j = 0;
		filepath[j++] = '/';
		for (i = 0; i < strlen(token); i++)
			filepath[j++] = token[i];
		filepath[j++] = '/';
		for (i = 0; i < strlen(argv[1]); i++)
			filepath[j++] = argv[1][i];
		/* filepath[j++] = '\n'; */
		/* check if the file exists */
		/* printf("%s\n", argv[1]); */
		if (stat(filepath, &st) == 0)
		{
			write(STDOUT_FILENO, filepath, strlen(filepath));
			write(STDOUT_FILENO, "\n", 1);
		}
		/* get the next directory in the PATH */
		token = strtok(NULL, ":");
	}
	return (0);
}
