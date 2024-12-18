/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_env_node_push.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/18 22:06:08 by maria         #+#    #+#                 */
/*   Updated: 2024/12/18 22:42:41 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	fn_env_node_push(t_env_node **head, t_env_node *new)
{
	t_env_node	*curr;

	if (*head == NULL || ft_strcmp((*head)->key, new->key) > 0)
	{
		new->next = *head;
		*head = new;
		return ;
	}
	curr = *head;
	while (curr->next && ft_strcmp(curr->next->key, new->key) < 0)
	{
		curr = curr->next;
	}
	new->next = curr->next;
	curr->next = new;
}
