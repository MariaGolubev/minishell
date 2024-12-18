/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_env_node_new.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 12:44:38 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/11/30 16:37:11 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_env_node	*fn_env_node_new(const char *key, const char *value)
{
	t_env_node	*new;

	if (!key)
		return (NULL);
	new = ft_calloc(1, sizeof(t_env_node));
	if (!new)
		return (NULL);
	new->key = ft_strdup(key);
	if (new->key == NULL)
		return (free(new), NULL);
	if (value == NULL)
		new->value = NULL;
	else
	{
		new->value = ft_strdup(value);
		if (new->value == NULL)
		{
			free(new->key);
			free(new);
			return (NULL);
		}
	}
	return (new);
}
