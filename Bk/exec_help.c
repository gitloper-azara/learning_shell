#include "a_shell.h"

/**
 * tokenise - splits a string into an array of words
 * @input: pointer to the string
 * @e_str: empty string
 *
 * Return: pointer to a char containing split words
 */

char **tokenise(char *input, char e_str)
{
	char **words = NULL, *copy = NULL, *token = NULL;
	int i, num = 0;

	copy = _strdup(input);
	if (!copy)
	{
		perror("Memory Allocation failure\n");
		free(copy);
		return (NULL);
	}

	words = malloc(sizeof(char *) * MAX_WORDS);
	if (!words)
	{
		free(words);
		return (NULL);
	}

	token = _strtok(copy, e_str);
	while (token)
	{
		if (token[0] != '\0')
		{
			words[num] = _strdup(token);
			if (!words[num])
			{
				perror("Memory Allocation failure\n");
				for (i = 0; i < num; i++)
					free(words[i]);
				free(words);
				free(copy);
				return (NULL);
			}
			num++;
			token = _strtok(NULL, e_str);
		}
	}

	free(copy);
	words[num] = NULL;
	return (words);
}

/**
 * _which - a function that finds executable files
 * @filename: executable file name to find
 *
 * Return: duplicate of the filepath, NULL if filepath can not be found
 */
/*
char *_which(char *filename)
{
	char *path;
	char *token;
	char *res;
	char filepath[BUFFER];
	struct stat st;

	if (file_exists(filename))
	{
		res = _strdup(filename);
		if (!res)
		{
			perror("Memory allocation failed\n");
			exit(EXIT_FAILURE);
		}
		return (res);
		printf("file (%s) found!/n", res);
	}

	path = _getenv("PATH");
	if (!path)
	{
		write(STDERR_FILENO, "Could not get path env variable.\n", 1);
		exit(1);
	}

	token = _strtok(path, ':');
	while (token != NULL)
	{
		_strcpy(filepath, token);
		_strcat(filepath, "/");
		_strcat(filepath, filename);
		printf("file added to token: %s\n", filepath);

		if (stat(filepath, &st) == 0)
		{
			res = _strdup(filepath);
			if (!res)
			{
				perror("Memory allocation failed\n");
				exit(EXIT_FAILURE);
			}
			return (res);
		}
		token = _strtok(NULL, ':');
	}

	_strcpy(filepath, path);
	_strcat(filepath, "/");
	_strcat(filepath, filename);
	printf("FILE (%s) found!\n", filepath);

	if (stat(filepath, &st) == 0)
	{
		res = _strdup(filepath);
		if (!res)
		{
			perror("Memory Allocation failed\n");
			exit(EXIT_FAILURE);
		}
		return (res);
	return (NULL);
} */

/**
 * file_exists - a function that checks the existence of a file in a path
 * @filename: file to check
 *
 * Return: 0 on success
 */

int file_exists(const char *filename)
{
	return (access(filename, F_OK) != -1);
}

/**
 * exec - a function that executes a command
 * @argv: double pointer to the a pointer that holds the command to execute
 *
 * Return: 0 on success
 */

int exec(char **argv)
{
	pid_t child_pid;
	int status;
	char *name = "./hsh";
	char *fullPATH;
	PathNode *head = '\0';
	static int cmdCounter = 1;

	if (!argv || !argv[0])
		return (0);

	if (file_exists(argv[0]))
	{
		child_pid = fork();
		if (child_pid == -1)
			fork_error(cmdCounter);
		else if (child_pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				execve_error(cmdCounter, name, argv[0]);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(child_pid, &status, 0);
			cmdCounter++;
			return (WEXITSTATUS(status));
		}
	}
	else
	{
		head = get_PathList();
		fullPATH = _which(argv[0], head);
		if (fullPATH)
		{
			child_pid = fork();
			if (child_pid == -1)
				fork_error(cmdCounter);
			else if (child_pid == 0)
			{
				if (execve(fullPATH, argv, environ) == -1)
				{
					execve_error(cmdCounter, fullPATH,
						     argv[0]);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				waitpid(child_pid, &status, 0);
				cmdCounter++;
				return (WEXITSTATUS(status));
			}
			free(fullPATH);
		}
		else
		{
			cmd_error(cmdCounter, name, argv[0]);
			cmdCounter++;
			exit(127);
		}
	}
	return (0);
}
