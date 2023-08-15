#include "sample_shell.h"

/**
 * _getline - reads an entire line from stream
 * @lineptr: contains the address of buffer containing text read from stream
 * @n: size of buffer
 * @stream: where to read text from
 * Return: On success, return number of chars read or -1 on failure to read
 * a line. On error, errno is set to indicate the cause.
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	size_t size;
	size_t i = 0;
	int c;
	char *temp;

	size = *n;
	if (*lineptr == NULL || size == 0)
	{
		size = 128; /* initial buffer size */
		*lineptr = malloc(size);
		if (*lineptr == NULL)
			return (-1); /* memory allocation failure */
		*n = size;
	}

	c = fgetc(stream);
	while (c != EOF)
	{
		if (i == size - 1)
		{
			size = size * 2; /* double the buffer sizer */
			temp = realloc(*lineptr, size);
			if (temp == NULL)
				return (-1); /* memory allocation failure */
			*lineptr = temp;
			*n = size;
		}
		(*lineptr)[i++] = c;
		if (c == '\n')
			break; /* stop reading at newline */
	}
	(*lineptr)[i] = '\0'; /* null-terminate the string */
	if (i == 0 && c == EOF)
		return (-1); /* no characters read */
	return (i); /* number of characters read */
}
