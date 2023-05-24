#include "shell.h"

/**
 * _myhistory - displays the history list, one command by line,
 * preceded with line numbers, starting at 0.
 *  Return: Always 0
 *  @info: Structure containing potential arguments.
 *  Used to maintain constant function prototype.
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to a  string
 * @info: parameter struct
 * @str: the string alias
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *l, k;
	int ret;

	l = _strchr(str, '=');
	if (!l)
		return (1);
	k = *l;
	*l = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*l = k;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * Return: 1 on error and 0 on success
 * @str: the string alias
 */
int set_alias(info_t *info, char *str)
{
	char *l;

	l = _strchr(str, '=');
	if (!l)
		return (1);
	if (!*++l)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * Return: 1 on error and 0 on success
 * @node: the alias node
 */
int print_alias(list_t *node)
{
	char *l = NULL, *b = NULL;

	if (node)
	{
		l = _strchr(node->str, '=');
		for (b = node->str; b <= l; b++)
		_putchar(*b);
		_putchar('\'');
		_puts(l + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin
 * @info: Structure containing potential arguments.
 * Used to maintain constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *l = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		l = _strchr(info->argv[i], '=');
		if (l)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

