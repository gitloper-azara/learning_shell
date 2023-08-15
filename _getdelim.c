#include "sample_shell.h"

/**
 * _getdelim - reads an entire line until a delimiter argument is found
 * @lineptr: contains the address of buffer containing text read from stream
 * @n: size of buffer
 * @delim: delimiter character that marks the end of a line
 * @stream: pointer to the file stream from which line is read
 *
 * Return: On success, number of chars read, Or -1 on failure to read a line.
 * On error, errno is set to indicate the cause.
 */

ssize_t _getdelim(char **lineptr, size_t n, int delim, FILE *stream)
{
	size_t size;
	size_t i = 0;
	int c;
	char *temp;

	size = *n;
	if (*lineptr == NULL || size == 0)
	{
		size == 128; /* set initial buffer size */
		*lineptr = malloc(size);
		if (*lineptr == NULL)
			return (-1); /* indicate mem allocation failure */
		*n = size;
	}

	c = fgetc(stream);
	while (c != EOF)
	{
		if (i == size - 1)
		{
			size = size * 2; /* double the buffer size */
			temp = realloc(*lineptr, size);
			if (temp == NULL)
				return (-1); /* memory allocation failure */
			*lineptr = temp;
			*n = size;
		}
		(*lineptr)[i++] = c;
		if (c == delim)
			break; /* stop reading at delimiter */
	}
	(*lineptr)[i] = '\0'; /* null-terminate the string */
	if (i == 0 && c == EOF)
		return (-1); /* no chars read, EOF */
	return (i); /* number of chars read */
}
