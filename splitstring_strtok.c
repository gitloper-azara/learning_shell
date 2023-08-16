#include "split.h"

/**
 * string_split - spilts a string into an array of words
 * @input: pointer to the string
 * @num: pointer to the number of words
 *
 * Return: pointer to a char containing the split words
 */

char **string_split(const char *input, int *num)
{
	char **words, *copy, *token;
	*num = 0;

	words = malloc(sizeof(char *) * MAX_WORDS);
	if (words == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	copy = strdup(input);
	if (copy == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(copy, " ");
	while (token != NULL)
	{
		words[*num] = strdup(token);
		if (words[*num] == NULL)
		{
			fprintf(stderr, "Memory allocation failed\n");
			exit(EXIT_FAILURE);
		}
		(*num)++;
		token = strtok(NULL, " ");
	}
	free(copy);
	return (words);
}
