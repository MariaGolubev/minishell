/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_builtin_cd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/12 14:14:29 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/16 17:13:03 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static void	fn_append_helper(t_executer*exec, char *key, char *value)
{
	t_env_node	*new;

	new = fn_env_node_new(key, value);
	if (new == NULL)
	{
		errno = ENOMEM;
		return ;
	}
	fn_env_node_append(&exec->envs->global_envs, new);
}

static int	fn_change_dir(t_executer *exec, char *path)
{
	char	*tmp;
	char	*old;

	old = exec->pwd;
	if (chdir(path) == -1)
		return (perror("chdir"), 1);
	if (fn_env_node_get_value(exec->envs->global_envs, "OLDPWD"))
	{
		if (fn_env_node_set(exec->envs->global_envs, "OLDPWD", old) == false)
			return (ft_putendl_fd("Error setting variable", 2), 1);
	}
	else
		fn_append_helper(exec, "OLDPWD", old);
	if (fn_env_node_get_value(exec->envs->global_envs, "PWD"))
	{
		if (fn_env_node_set(exec->envs->global_envs, "PWD", path) == false)
			return (ft_putendl_fd("Error setting variable", 2), 1);
	}
	else
		fn_append_helper(exec, "PWD", path);
	tmp = ft_strdup(fn_env_node_get_value(exec->envs->global_envs, "PWD"));
	if (tmp == NULL)
		return (errno = ENOMEM, -1);
	(free(exec->pwd), exec->pwd = tmp);
	return (0);
}

static int	fn_check_args(char *path)
{
	if (path == NULL)
		return (ft_putendl_fd("minishell: cd: no directory", 2), 1);
	if (path[0] == '-')
	{
		ft_putendl_fd("minishell: cd: invalid option", 2);
		ft_putendl_fd("minishell: cd: usage: cd [dir]", 2);
		return (2);
	}
	return (0);
}

static char	*fn_get_cd_path(t_executer *exec, char **argv)
{
	char	*buf;

	if (argv[1][0] == '/')
	{
		buf = ft_strdup("/");
		if (buf == NULL)
			return (NULL);
	}
	else
	{
		buf = ft_strdup(exec->pwd);
		if (buf == NULL)
			return (NULL);
	}
	if (fn_resolve(argv, &buf, 1))
	{
		free(buf);
		return (NULL);
	}
	if (fn_check_dir(argv, buf))
		return (NULL);
	return (buf);
}

int	fn_builtin_cd(t_executer *exec, int argc, char **argv)
{
	char	*path;
	int		ret;

	path = NULL;
	if (argc > 2)
	{
		ft_putendl_fd("minishell: cd: too many arguments", 2);
		return (EXIT_FAILURE);
	}
	if (argc == 1)
	{
		return (EXIT_SUCCESS);
	}
	if (fn_check_args(argv[1]))
		return (EXIT_FAILURE);
	path = fn_get_cd_path(exec, argv);
	if (path == NULL)
		return (EXIT_FAILURE);
	ret = fn_change_dir(exec, path);
	free(path);
	if (ret != 0 || errno == ENOMEM)
		return (EXIT_FAILURE);
	return (ret);
}
