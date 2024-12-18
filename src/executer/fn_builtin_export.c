/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_builtin_export.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/11 14:39:26 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/17 13:44:34 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static int	fn_is_envkey(char *key)
{
	if (!key || ft_isdigit(*key))
		return (0);
	while (*key && (ft_isalnum(*key) || *key == '_'))
		key++;
	return (*key == '\0');
}

static int	fn_export(t_executer *exec, char *key, char *value, char *argv)
{
	if (ft_strchr(argv, '='))
	{
		key = ft_substr(argv, 0, ft_strchr(argv, '=') - argv);
		value = ft_substr(argv,
				(ft_strchr(argv, '=') - argv) + 1, ft_strlen(argv));
	}
	else
		key = ft_strdup(argv);
	if (!fn_is_envkey(key))
	{
		free(key);
		if (value)
			free(value);
		ft_putendl_fd("export: invalid key", 2);
		return (EXIT_FAILURE);
	}
	fn_envs_export(exec->envs, key, value);
	free(key);
	if (value)
		free(value);
	return (EXIT_SUCCESS);
}

static int	fn_check_validity(char *s)
{
	int	i;

	if (!ft_isalpha(s[0]) && s[0] != '_')
		return (1);
	i = -1;
	while (s[++i])
	{
		if (s[i] == '=')
			break ;
		if (!ft_isalpha(s[i]) && !ft_isdigit(s[i]) && s[i] != '_')
			return (1);
	}
	return (0);
}

int	fn_builtin_export(t_executer *exec, int argc, char **argv)
{
	char	*key;
	char	*value;

	value = NULL;
	key = NULL;
	if (argc == 1)
		return (fn_builtin_export_print(exec));
	while (argv[1] != NULL)
	{
		if (fn_check_validity(argv[1]))
		{
			ft_putstr_fd("-minishell: export `", STDERR_FILENO);
			ft_putstr_fd(argv[1], STDERR_FILENO);
			ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
		if (fn_export(exec, key, value, argv[1]))
			return (EXIT_FAILURE);
		argv++;
	}
	return (EXIT_SUCCESS);
}
