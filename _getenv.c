#include <stdio.h>
extern char **environ;

char *_getenv(const char *name)
{
	/* char **env = environ; */
	/* char *env_var = *environ; */
	char *value;
	unsigned int i, j;

	i = 0;
	while (*environ[i])
	{
		j = 0;
		if (name[j] == environ[i][j])
		{
			while (name[j])
			{
				if (name[j] != environ[i][j])
					break;
				j++;
			}
			if (name[j] == '\0')
			{
				value = (environ[i] + j + 1);
				return (value);
			}
		}
		i++;
	}
	return (0);
}

/**
 * main - prints the PATH
 *
 * Return: Always 0.
 */

int main(void)
{
	const char *path;

	path = _getenv("PATH");
	if (path)
		printf("PATH = %s\n", path);
	else
		printf("PATH not found in the environment variables.\n");
	return (0);
}
