#include "split.h"

int main(void)
{
	const char *input;
	char **words;
	int num, i;

	input = "Hello world this is a test";
	words = string_split(input, &num);

	for (i = 0; i < num; i++)
	{
		printf("Word %d: %s\n", i, words[i]);
		free(words[i]);
	}
	free(words);

	return (0);
}
