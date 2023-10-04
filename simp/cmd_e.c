#include "shell.h"


/**
 * _dir_or_not - checks the current dic.
 * @p: path.
 * @x: pointer
 * Return: 1 if  p is in ,0 not.
 */
int _dir_or_not(char *p, int *x)
{
	if (p[*x] == ':')
		return (1);

	while (p[*x] != ':' && p[*x])
	{
		*x += 1;
	}

	if (p[*x])
		*x += 1;

	return (0);
}

/**
 * _is_that - locates a command
 *
 * @command: command
 * @_env: environment
 * Return: palce
 */
char *_is_that(char *command, char **_env)
{
	char *esl, *ash, *ala, *abd;
	int moh, aza, x;
	struct stat eid;

	esl = _have_env("PATH", _env);
	if (esl)
	{
		ash = _string_duplicates(esl);
		aza = _string_length(command);
		ala = _string_toknaization(ash, ":");
		x = 0;
		while (ala != NULL)
		{
			if (_dir_or_not(esl, &x))
				if (stat(command, &eid) == 0)
					return (command);
			moh = _string_length(ala);
			abd = malloc(moh + aza + 2);
			_string_copy(abd, ala);
			_string_add(abd, "/");
			_string_add(abd, command);
			_string_add(abd, "\0");
			if (stat(abd, &eid) == 0)
			{
				free(ash);
				return (abd);
			}
			free(abd);
			ala = _string_toknaization(NULL, ":");
		}
		free(ash);
		if (stat(command, &eid) == 0)
			return (command);
		return (NULL);
	}
	if (command[0] == '/')
		if (stat(command, &eid) == 0)
			return (command);
	return (NULL);
}

/**
 * _exe_or_not - executable or not
 *
 * @hash: data
 * Return: 1 exe , 0 not
 */
int _exe_or_not(main_data *hash)
{
	struct stat ali;
	int i;
	char *c;

	c = hash->as[0];
	for (i = 0; c[i]; i++)
	{
		if (c[i] == '.')
		{
			if (c[i + 1] == '.')
				return (0);
			if (c[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (c[i] == '/' && i != 0)
		{
			if (c[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
	}
	if (i == 0)
		return (0);

	if (stat(c + i, &ali) == 0)
	{
		return (i);
	}
	_get_all_err(hash, 127);
	return (-1);
}

/**
 * _is_err - has permissions or not
 *
 * @directory: directory
 * @hash: data
 * Return: 1 err, 0 not
 */
int _is_err(char *directory, main_data *hash)
{
	if (directory == NULL)
	{
		_get_all_err(hash, 127);
		return (1);
	}

	if (_string_compare(hash->as[0], directory) != 0)
	{
		if (access(directory, X_OK) == -1)
		{
			_get_all_err(hash, 126);
			free(directory);
			return (1);
		}
		free(directory);
	}
	else
	{
		if (access(hash->as[0], X_OK) == -1)
		{
			_get_all_err(hash, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * _executable - executes cmd l
 *
 * @hash: data
 * Return: 1 on success.
 */
int _executable(main_data *hash)
{
	pid_t m10;
	pid_t cr7;
	int kb9;
	int kdb17;
	char *ai8;
	(void) cr7;

	kdb17 = _exe_or_not(hash);
	if (kdb17 == -1)
		return (1);
	if (kdb17 == 0)
	{
		ai8 = _is_that(hash->as[0], hash->_environment);
		if (_is_err(ai8, hash) == 1)
			return (1);
	}

	m10 = fork();
	if (m10 == 0)
	{
		if (kdb17 == 0)
			ai8 = _is_that(hash->as[0], hash->_environment);
		else
			ai8 = hash->as[0];
		execve(ai8 + kdb17, hash->as, hash->_environment);
	}
	else if (m10 < 0)
	{
		perror(hash->argv[0]);
		return (1);
	}
	else
	{
		do {
			cr7 = waitpid(m10, &kb9, WUNTRACED);
		} while (!WIFEXITED(kb9) && !WIFSIGNALED(kb9));
	}

	hash->sstt = kb9 / 256;
	return (1);
}
