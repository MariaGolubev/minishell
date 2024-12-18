/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_double_quote_to_str.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 17:35:16 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/16 17:46:56 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static char	*fn_escaping(const char **str)
{
	(*str)++;
	if (**str == '$')
		return ((*str)++, ft_strdup("$"));
	else if (**str == '\"')
		return ((*str)++, ft_strdup("\""));
	else if (**str == '\'')
		return ((*str)++, ft_strdup("'"));
	else if (**str == 'a')
		return ((*str)++, ft_strdup("\a"));
	else if (**str == 'b')
		return ((*str)++, ft_strdup("\b"));
	else if (**str == 't')
		return ((*str)++, ft_strdup("\t"));
	else if (**str == 'n')
		return ((*str)++, ft_strdup("\n"));
	else if (**str == 'v')
		return ((*str)++, ft_strdup("\v"));
	else if (**str == 'f')
		return ((*str)++, ft_strdup("\f"));
	else if (**str == 'r')
		return ((*str)++, ft_strdup("\r"));
	return (NULL);
}

static char	*fn_variable(const char **str, t_envs *envs)
{
	const char	*orig;
	char		*key;
	char		*value;

	orig = *str;
	(*str)++;
	if (**str == '?')
		(*str)++;
	else
	{
		while (ft_isalnum(**str) || **str == '_')
			(*str)++;
	}
	key = ft_substr(orig + 1, 0, *str - orig - 1);
	if (key == NULL)
		return (NULL);
	value = fn_envs_get_value(envs, key);
	free(key);
	if (value)
		return (ft_strdup(value));
	else
		return (ft_calloc(1, sizeof(char)));
}

static char	*fn_simple(const char **str)
{
	const char	*orig = *str;

	while (**str)
	{
		if (**str == '\\' && ft_strchr("abtnvfr$'\"\\", (*str)[1]))
			break ;
		else if (**str == '$' && !ft_isdigit((*str)[1]) &&
				(ft_isalnum((*str)[1]) || (*str)[1] == '_'))
			break ;
		else if (**str == '$' && (*str)[1] == '?')
			break ;
		(*str)++;
	}
	return (ft_substr(orig, 0, *str - orig));
}

char	*fn_double_quote_to_str(const char *str, t_envs *envs)
{
	char	*out;
	char	*tmp;
	char	*part;

	out = ft_calloc(1, sizeof(char));
	if (out == NULL)
		return (NULL);
	while (*str)
	{
		if (*str == '\\' && ft_strchr("abtnvfr$'\"\\", str[1]))
			part = fn_escaping(&str);
		else if (*str == '$' && !ft_isdigit(str[1]) && \
				(ft_isalnum(str[1]) || ft_strchr("_?", str[1])))
			part = fn_variable(&str, envs);
		else
			part = fn_simple(&str);
		if (part == NULL)
			return (free(out), NULL);
		tmp = ft_strjoin(out, part);
		(free(out), free(part));
		out = tmp;
		if (out == NULL)
			return (NULL);
	}
	return (out);
}
