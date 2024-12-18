/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_builtin_unset.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/12 17:46:02 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/16 12:00:34 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static int	fn_is_key(t_env_node *env, char *key)
{
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (1);
		env = env->next;
	}
	return (0);
}

static int	fn_envs_is_key(t_envs *envs, char *key)
{
	if (fn_is_key(envs->shel_env, key) || fn_is_key(envs->global_envs, key))
		return (1);
	return (0);
}

int	fn_builtin_unset(t_executer *exec, int argc, char **argv)
{
	t_env_node	*removed_node;

	if (argc == 1)
		return (0);
	while (argv[1] != NULL)
	{
		if (fn_envs_is_key(exec->envs, argv[1]))
		{
			if (fn_is_key(exec->envs->global_envs, argv[1]))
				removed_node = fn_env_node_take(&exec->envs->global_envs,
						argv[1]);
			else
				removed_node = fn_env_node_take(&exec->envs->shel_env, argv[1]);
			fn_env_node_free(&removed_node);
			removed_node = NULL;
		}
		argv++;
	}
	return (0);
}
