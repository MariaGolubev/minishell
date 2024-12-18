/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_env_node_free.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 12:43:14 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/11/30 16:36:59 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	fn_env_node_free(t_env_node **env)
{
	t_env_node	*curr;
	t_env_node	*next;

	if (!env || !*env)
		return ;
	curr = *env;
	while (curr)
	{
		next = curr->next;
		if (curr->key)
			(free(curr->key), curr->key = NULL);
		if (curr->value)
			(free(curr->value), curr->value = NULL);
		(free(curr), curr = NULL);
		curr = next;
	}
	*env = NULL;
}
