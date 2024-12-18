/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_ast_values_to_str.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/12 10:16:54 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/16 17:45:57 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static char	*fn_join_double_quote(const char *str,
			const char *value, t_envs *envs)
{
	char	*double_q;
	char	*tmp;

	double_q = fn_double_quote_to_str(value, envs);
	if (double_q == NULL)
		return (NULL);
	tmp = ft_strjoin(str, double_q);
	free(double_q);
	return (tmp);
}

static char	*fn_join_variable(const char *str,
			const char *key, t_envs *envs)
{
	char	*tmp;

	if (fn_envs_get_value(envs, key))
		tmp = ft_strjoin(str, fn_envs_get_value(envs, key));
	else
		tmp = ft_strdup(str);
	return (tmp);
}

char	*fn_ast_values_to_str(t_ast_value *values, t_envs *envs)
{
	char	*str;
	char	*tmp;

	str = ft_calloc(1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (values)
	{
		tmp = NULL;
		if (values->type == VALUE_WORD)
			tmp = ft_strjoin(str, values->value);
		else if (values->type == VALUE_WORD_DOUBLE_QUOTE)
			tmp = fn_join_double_quote(str, values->value, envs);
		else if (values->type == VALUE_VARIABLE)
			tmp = fn_join_variable(str, values->value, envs);
		free(str);
		str = tmp;
		if (str == NULL)
			return (NULL);
		values = values->next;
	}
	return (str);
}
