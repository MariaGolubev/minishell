/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_env_node_append.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 12:42:18 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/11/30 16:36:51 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	fn_env_node_append(t_env_node **head, t_env_node *new)
{
	t_env_node	*curr;

	if (!*head)
	{
		*head = new;
		return ;
	}
	curr = *head;
	while (curr->next)
		curr = curr->next;
	curr->next = new;
	return ;
}
