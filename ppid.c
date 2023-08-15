#include <stdio.h>
#include <unistd.h>

/**
 * main - PPID
 *
 * Return: always 0
 */

int main(void)
{
	pid_t my_PPID;

	my_PPID = getppid();
	printf("%u\n", my_PPID);

	return (0);
}
