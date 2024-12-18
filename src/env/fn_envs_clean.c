/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_envs_clean.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 16:40:06 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/10 21:25:55 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	fn_envs_clean_all(t_envs **envs)
{
	if (envs == NULL || *envs == NULL)
		return ;
	fn_env_node_free(&(*envs)->global_envs);
	fn_env_node_free(&(*envs)->program_env);
	fn_env_node_free(&(*envs)->shel_env);
	free((*envs)->status);
	free(*envs);
	*envs = NULL;
}
