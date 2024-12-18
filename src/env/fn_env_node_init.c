/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_env_node_init.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/29 14:31:14 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/16 17:08:24 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*fn_env_node_extract_key(char *key)
{
	int	i;

	i = 0;
	while (key[i])
	{
		if (key[i] == '=')
			return (ft_substr(key, 0, i));
		i++;
	}
	return (ft_strdup(key));
}

char	*fn_env_node_extract_value(char *value)
{
	int	i;

	i = 0;
	while (value[i])
	{
		if (value[i] == '=')
		{
			i++;
			if (value[i])
				return (ft_substr(value, i, ft_strlen(value) - i));
			else
				return (ft_strdup(""));
		}
		i++;
	}
	return (NULL);
}

t_env_node	*fn_env_node_init(char **envg)
{
	int			i;
	char		*key;
	char		*value;
	t_env_node	*local_env;
	t_env_node	*new;

	local_env = NULL;
	i = 0;
	while (envg[i])
	{
		key = fn_env_node_extract_key(envg[i]);
		if (!key)
			return (fn_env_node_free(&local_env), NULL);
		value = fn_env_node_extract_value(envg[i]);
		if (!value)
			return (free(key), fn_env_node_free(&local_env), NULL);
		new = fn_env_node_new(key, value);
		free(key);
		free(value);
		if (new == NULL)
			return (fn_env_node_free(&local_env), NULL);
		fn_env_node_append(&local_env, new);
		i++;
	}
	return (local_env);
}
