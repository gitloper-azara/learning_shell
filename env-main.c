#include <stdio.h>

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */

int main(int ac, char **av, char **env)
{
	unsigned int i;
	(void)ac;
	(void)av;

	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
