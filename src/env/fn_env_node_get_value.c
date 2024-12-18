/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_env_node_get_value.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 12:44:02 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/11/30 16:37:05 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*fn_env_node_get_value(t_env_node *env, const char *key)
{
	if (!env || !key)
		return (NULL);
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}
