#include <stdio.h>

/**
 * main - entry point of program
 * @av: NULL terminated array of strings
 * @ac: number of items in av
 *
 * Return: always 0;
 */

int main(int ac, char **av)
{
	(void)ac;
	int i;

	for (i = 0; av[i] != NULL; i++)
		printf("%s\n", av[i]);

	return (0);
}
