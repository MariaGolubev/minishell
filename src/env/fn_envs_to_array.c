/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_envs_to_array.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/07 17:23:50 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/13 12:24:19 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

bool	fn_env_node_contains_key(t_env_node *node, char *key)
{
	while (node)
	{
		if (node->key && ft_strncmp(node->key, key, ft_strlen(key)) == 0)
			return (true);
		node = node->next;
	}
	return (false);
}

int	fn_envs_count(t_envs *envs)
{
	t_env_node	*global;
	t_env_node	*program;
	int			size;

	global = envs->global_envs;
	program = envs->program_env;
	size = 0;
	while (program)
	{
		size++;
		program = program->next;
	}
	while (global)
	{
		if (fn_env_node_contains_key(envs->shel_env, global->key) == false)
			size++;
		global = global->next;
	}
	return (size);
}

static char	**fn_envs_to_array_helper(t_envs *envs, char **envp, int i)
{
	char		*joined;
	t_env_node	*global;

	global = envs->global_envs;
	joined = NULL;
	while (global)
	{
		if (fn_env_node_contains_key(envs->program_env, global->key) == false)
		{
			joined = ft_strjoin_with(global->key, global->value, '=');
			if (!joined)
				return (fn_envs_clean_all(&envs), NULL);
			envp[i++] = joined;
		}
		global = global->next;
	}
	envp[i] = NULL;
	return (envp);
}

char	**fn_envs_to_array(t_envs *envs)
{
	t_env_node	*program;
	char		**envp;
	char		*joined;
	int			size;
	int			i;

	if (!envs)
		return (NULL);
	if (fn_env_node_get_size(envs->program_env) == 0)
		return (fn_env_node_to_array(envs->global_envs));
	size = fn_envs_count(envs);
	envp = ft_calloc(sizeof(char *), size + 1);
	program = envs->program_env;
	i = 0;
	while (program)
	{
		joined = ft_strjoin_with(program->key, program->value, '=');
		if (!joined)
			return (fn_envs_clean_all(&envs), NULL);
		envp[i++] = joined;
		program = program->next;
	}
	return (fn_envs_to_array_helper(envs, envp, i));
}
