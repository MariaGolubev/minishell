/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_env_to_array.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/07 15:33:07 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/11 15:35:42 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	fn_env_node_get_size(t_env_node *env)
{
	int	i;

	i = 0;
	while (env)
	{
		if (env->value)
			i++;
		env = env->next;
	}
	return (i);
}

char	*ft_strjoin_with(char *s1, char *s2, char c)
{
	int		i;
	int		j;
	int		size;
	char	*p;

	size = ft_strlen(s1) + ft_strlen(s2);
	p = malloc(sizeof(char) * (size + 2));
	if (!p)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	if (c)
		p[i++] = c;
	j = 0;
	while (s2[j])
	{
		p[i + j] = s2[j];
		j++;
	}
	p[i + j] = 0;
	return (p);
}

char	**fn_env_node_to_array(t_env_node *env)
{
	t_env_node	*env_node;
	char		**envp;
	char		*joined;
	int			size;
	int			i;

	env_node = env;
	size = fn_env_node_get_size(env_node);
	envp = ft_calloc(size + 1, sizeof(char *));
	if (!envp)
		return (NULL);
	i = 0;
	while (env_node && i < size)
	{
		if (env_node->value)
		{
			joined = ft_strjoin_with(env_node->key, env_node->value, '=');
			if (!joined)
				return (fn_env_node_free(&env), NULL);
			envp[i] = joined;
			i++;
		}
		env_node = env_node->next;
	}
	return (envp);
}
