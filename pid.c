#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: always 0
 */

int main(void)
{
	pid_t my_PID;

	my_PID = getpid();
	printf("%u\n", my_PID);

	return (0);
}
