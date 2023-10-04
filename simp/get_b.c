#include "shell.h"

/**
 * have_b - builtin send cmd
 * @command: cmd
 * Return: pointer
 */

int (*have_b(char *command))(main_data *)
{
	internal_i b[] = {
		{ "env", _environment_env },
		{ "exit", _sh_exit },
		{ "setenv",  _ready_env },
		{ "unsetenv", _not_ready_env },
		{ "cd", _cd_5 },
		{ "help", _call_h },
		{ NULL, NULL }
	};
	int x;

	for (x = 0; b[x].identifier; x++)
	{
		if (_string_compare(b[x].identifier, command) == 0)
			break;
	}

	return (b[x].function);
}
