#include "shell.h"

/**
 * _sig - manage ctrl
 * @s: handler
 */
void _sig(int s)
{
	(void)s;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
