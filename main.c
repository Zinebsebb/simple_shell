#include "shell.h"

/**
 * main - entry point
 * Return: 1 on error and 0 on success
 * @co: arg count
 * @ve: arg vector
 */
int main(int co, char **ve)
{
	info_t info[] = { INFO_INIT };
	int df = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (df)
			: "r" (df));

	if (co == 2)
	{
		df = open(ve[1], O_RDONLY);
		if (df == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(ve[0]);
				_eputs(": 0: Can't open ");
				_eputs(ve[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = df;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, ve);
	return (EXIT_SUCCESS);
}

