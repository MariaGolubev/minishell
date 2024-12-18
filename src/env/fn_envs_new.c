/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_envs_new.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/07 16:51:23 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/10 21:10:24 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_envs	*fn_envs_new(char **env)
{
	t_env_node	*global;
	t_envs		*envs;

	envs = ft_calloc(1, sizeof(t_envs));
	if (!envs)
		return (NULL);
	global = fn_env_node_init(env);
	if (!global)
	{
		free(envs);
		return (NULL);
	}
	envs->status = ft_itoa(0);
	if (envs->status == NULL)
	{
		free(envs);
		free(global);
		return (NULL);
	}
	envs->global_envs = global;
	envs->shel_env = NULL;
	envs->program_env = NULL;
	return (envs);
}
