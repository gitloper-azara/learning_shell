#include "sample_shell.h"

int main(void)
{
	ssize_t read;
	char *lineptr = NULL;
	size_t len = 0;

	while (1)
	{
		printf("$ ");

		read = _getline(&lineptr, &len, stdin);

		if (read == -1)
			break;
		printf("%s", lineptr);
	}

	free(lineptr);

	return (0);
}

