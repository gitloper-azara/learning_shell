#ifndef STRING_H
#define STRING_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50

char **string_split(const char *input, int *num);

#endif /* STRING_H */
