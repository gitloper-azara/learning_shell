#include <stdio.h>
extern char **environ;

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */

int main(int ac, char **av, char **env)
{
	unsigned int i;
	(void)env;
	(void)ac;
	(void)av;

	i = 0;
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
