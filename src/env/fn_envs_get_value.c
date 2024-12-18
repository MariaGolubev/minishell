/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_envs_get_value.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/07 17:21:33 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/16 18:10:04 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*fn_envs_get_value(t_envs *envs, const char *key)
{
	char	*value;

	if (ft_strcmp(key, "?") == 0)
		return (envs->status);
	value = fn_env_node_get_value(envs->shel_env, key);
	if (!value)
		value = fn_env_node_get_value(envs->global_envs, key);
	return (value);
}
