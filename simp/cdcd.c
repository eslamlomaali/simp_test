#include "shell.h"

/**
 * _cd_1 - parent dir
 *
 * @hash: data
 *
 * Return: void
 */
void _cd_1(main_data *hash)
{
	char pp_d[PATH_MAX];
	char *directory, *cpp_i, *cp_s_p;

	getcwd(pp_d, sizeof(pp_d));
	cpp_i = _string_duplicates(pp_d);
	_setup_env("OLDPWD", cpp_i, hash);
	directory = hash->as[1];
	if (_string_compare(".", directory) == 0)
	{
		_setup_env("PWD", cpp_i, hash);
		free(cpp_i);
		return;
	}
	if (_string_compare("/", cpp_i) == 0)
	{
		free(cpp_i);
		return;
	}
	cp_s_p = cpp_i;
	_revers_string(cp_s_p);
	cp_s_p = _string_toknaization(cp_s_p, "/");
	if (cp_s_p != NULL)
	{
		cp_s_p = _string_toknaization(NULL, "\0");

		if (cp_s_p != NULL)
			_revers_string(cp_s_p);
	}
	if (cp_s_p != NULL)
	{
		chdir(cp_s_p);
		_setup_env("PWD", cp_s_p, hash);
	}
	else
	{
		chdir("/");
		_setup_env("PWD", "/", hash);
	}
	hash->sstt = 0;
	free(cpp_i);
}

/**
 * _cd_2 - changes dir
 *
 * @hash: data
 * Return: void
 */
void _cd_2(main_data *hash)
{
	char pp_d[PATH_MAX];
	char *directory, *cpp_i, *cp_directory;

	getcwd(pp_d, sizeof(pp_d));

	directory = hash->as[1];
	if (chdir(directory) == -1)
	{
		_get_all_err(hash, 2);
		return;
	}

	cpp_i = _string_duplicates(pp_d);
	_setup_env("OLDPWD", cpp_i, hash);

	cp_directory = _string_duplicates(directory);
	_setup_env("PWD", cp_directory, hash);

	free(cpp_i);
	free(cp_directory);

	hash->ss = 0;

	chdir(directory);
}

/**
 * _cd_3 - prev dir
 *
 * @hash: data
 * Return: void
 */
void _cd_3(main_data *hash)
{
	char pp_d[PATH_MAX];
	char *pp_i, *p_o, *cpp_i, *cp_o;

	getcwd(pp_d, sizeof(pp_d));
	cpp_i = _string_duplicates(pp_d);

	p_o = _have_env("OLDPWD", hash->_environment);

	if (p_o == NULL)
		cp_o = cpp_i;
	else
		cp_o = _string_duplicates(p_o);

	_setup_env("OLDPWD", cpp_i, hash);

	if (chdir(cp_o) == -1)
		_setup_env("PWD", cpp_i, hash);
	else
		_setup_env("PWD", cp_o, hash);

	pp_i = _have_env("PWD", hash->_environment);

	write(STDOUT_FILENO, pp_i, _string_length(pp_i));
	write(STDOUT_FILENO, "\n", 1);

	free(cpp_i);
	if (p_o)
		free(cp_o);

	hash->sstt = 0;

	chdir(pp_i);
}

/**
 * _cd_4 - home dir
 *
 * @hash: data
 * Return: void
 */
void _cd_4(main_data *hash)
{
	char *pp_i, *h;
	char pp_d[PATH_MAX];

	getcwd(pp_d, sizeof(pp_d));
	pp_i = _string_duplicates(pp_d);

	h = _have_env("HOME", hash->_environment);

	if (h == NULL)
	{
		_setup_env("OLDPWD", pp_i, hash);
		free(pp_i);
		return;
	}

	if (chdir(h) == -1)
	{
		_get_all_err(hash, 2);
		free(pp_i);
		return;
	}

	_have_env("OLDPWD", pp_i, hash);
	_have_env("PWD", h, hash);
	free(pp_i);
	hash->sstt = 0;
}
