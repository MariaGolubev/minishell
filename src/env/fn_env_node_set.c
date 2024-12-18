/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_env_node_set.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/02 13:17:37 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/16 18:09:18 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static int	fn_is_key(t_env_node *env, const char *key)
{
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (1);
		env = env->next;
	}
	return (0);
}

static bool	fn_set(t_env_node *env, const char *key, const char *new_vl)
{
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
		{
			free(env->value);
			env->value = NULL;
			if (new_vl)
				env->value = ft_strdup(new_vl);
			if (!env->value)
				return (false);
			return (true);
		}
		env = env->next;
	}
	return (true);
}

bool	fn_env_node_set(t_env_node *env, const char *key, const char *new_vl)
{
	t_env_node	*new;

	if (fn_is_key(env, key) && new_vl == NULL)
		return (true);
	if (fn_is_key(env, key) == 0)
	{
		new = fn_env_node_new(key, new_vl);
		if (new == NULL)
			return (false);
		fn_env_node_append(&env, new);
		return (true);
	}
	return (fn_set(env, key, new_vl));
}
