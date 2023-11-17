#include "a_shell.h"

/**
 * _strncpy - copies a string
 * @dest: destination
 * @src: source
 * @len: number of times to copy
 *
 * Return: dest
 */

char *_strncpy(char *dest, const char *src, size_t len)
{
	size_t i;

	for (i = 0; i < len && *(src + i); i++)
		*(dest + i) = *(src + i);

	for (; i < len; i++)
		*(dest) = '\0';
	return (dest);
}

/**
 * concat - a function that concatenates strings in newly alloc'd memory
 * @name: name of path
 * @div: separator
 * @file: file
 *
 * Return: pointer to new str
 */

char *concat(char *name, char *div, char *file)
{
	char *res;
	int len1 = _strlen(name);
	int len2 = _strlen(div);
	int len3 = _strlen(file);
	int i, j;

	res = malloc(len1 + len2 + len3 + 1);
	if (!res)
		return (NULL);
	for (i = 0; name[i]; i++)
		res[i] = name[i];
	j = i;

	for (i = 0; div[i]; i++)
		res[j + i] = div[i];
	j = j + i;

	for (i = 0; file[i]; i++)
		res[j + i] = file[i];
	j = j + i;

	res[j] = '\0';
	return (res);
}
