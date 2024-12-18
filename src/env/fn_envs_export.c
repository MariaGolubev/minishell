/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_envs_export.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/11 16:47:04 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/16 17:09:53 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_env_node	*fn_env_node_take(t_env_node **head, const char *key)
{
	t_env_node	*prev;
	t_env_node	*current;

	prev = NULL;
	current = *head;
	while (current && ft_strcmp(current->key, key) != 0)
	{
		prev = current;
		current = current->next;
	}
	if (current)
	{
		if (prev)
			prev->next = current->next;
		else
			*head = current->next;
		current->next = NULL;
	}
	return (current);
}

void	fn_env_node_delone(t_env_node **head, const char *key)
{
	t_env_node	*node;

	node = fn_env_node_take(head, key);
	if (node)
	{
		if (node->key)
			free(node->key);
		if (node->value)
			free(node->value);
		free(node);
	}
}

void	fn_envs_export(t_envs *envs, const char *key, const char *value)
{
	t_env_node	*tmp;

	if (value == NULL && fn_env_node_get_value(envs->global_envs, (char *)key))
		return ;
	if (value == NULL)
	{
		if (fn_env_node_get_value(envs->shel_env, (char *)key))
		{
			tmp = fn_env_node_take(&envs->shel_env, key);
			fn_env_node_append(&envs->global_envs, tmp);
		}
		else
		{
			tmp = fn_env_node_new(key, NULL);
			fn_env_node_append(&envs->global_envs, tmp);
		}
	}
	else
	{
		fn_env_node_delone(&envs->shel_env, key);
		fn_env_node_delone(&envs->global_envs, key);
		tmp = fn_env_node_new(key, value);
		fn_env_node_append(&envs->global_envs, tmp);
	}
}
