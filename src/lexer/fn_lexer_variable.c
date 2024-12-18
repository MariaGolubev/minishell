/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_lexer_variable.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/28 20:18:45 by maria         #+#    #+#                 */
/*   Updated: 2024/12/10 21:37:48 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	fn_env_len(const char *input)
{
	int		len;

	len = 1;
	if (!ft_isdigit(*input) && (ft_isalpha(*input) || *input == '_'))
	{
		input++;
		len++;
	}
	while ((ft_isalnum(*input) || *input == '_'))
	{
		input++;
		len++;
	}
	return (len);
}

static void	fn_env_cpy(const char **input, char *buffer)
{
	int		index;

	index = 1;
	buffer[0] = '$';
	if (!ft_isdigit(**input) && (ft_isalpha(**input) || **input == '_'))
	{
		buffer[index++] = **input;
		(*input)++;
	}
	while ((ft_isalnum(**input) || **input == '_'))
	{
		buffer[index++] = **input;
		(*input)++;
	}
	buffer[index] = '\0';
}

t_lexer_state_type	fn_lexer_variable(const char **input, t_token **tokens)
{
	char	*buffer;
	t_token	*token;

	if (**input == '$')
		(*input)++;
	if (**input == '?')
	{
		token = fn_token_new(TOKEN_VARIABLE, "$?");
		if (token == NULL)
			return (LEXER_ERR);
		fn_token_add(tokens, token);
		(*input)++;
		return (fn_lexer_next_state(*input));
	}
	buffer = (char *)(malloc((fn_env_len(*input) + 1) * sizeof(char)));
	if (buffer == NULL)
		return (LEXER_ERR);
	fn_env_cpy(input, buffer);
	token = fn_token_new(TOKEN_VARIABLE, buffer);
	free(buffer);
	if (token == NULL)
		return (LEXER_ERR);
	fn_token_add(tokens, token);
	return (fn_lexer_next_state(*input));
}
