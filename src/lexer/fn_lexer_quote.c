/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_lexer_quote.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/28 20:14:04 by maria         #+#    #+#                 */
/*   Updated: 2024/12/12 11:47:58 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "stdio.h"

static int	fn_quote_len(const char *input, char ch)
{
	int	len;

	len = 0;
	while (*input != ch && *input != '\0')
	{
		len++;
		input++;
	}
	return (len);
}

static void	fn_quote_cpy(const char **input, char *buffer, char ch)
{
	int		index;

	index = 0;
	while (**input != ch && **input != '\0')
	{
		if ((*input)[0] == '\\' && (*input)[1] == ch)
		{
			buffer[index++] = ch;
			(*input) += 2;
		}
		else
		{
			buffer[index++] = **input;
			(*input)++;
		}
	}
	buffer[index] = '\0';
}

t_lexer_state_type	fn_lexer_single_quote(const char **input, t_token **tokens)
{
	char	*buffer;
	int		len;
	t_token	*token;

	(*input)++;
	len = fn_quote_len(*input, '\'');
	buffer = (char *)malloc((len + 1) + sizeof(char));
	if (buffer == NULL)
		return (LEXER_ERR);
	fn_quote_cpy(input, buffer, '\'');
	if (**input == '\'')
		(*input)++;
	else
	{
		free(buffer);
		return (LEXER_ERR_SINGLE_QUOTE);
	}
	token = fn_token_new(TOKEN_STRING_SINGLE, buffer);
	free(buffer);
	if (token == NULL)
		return (LEXER_ERR);
	fn_token_add(tokens, token);
	return (fn_lexer_next_state(*input));
}

t_lexer_state_type	fn_lexer_double_quote(const char **input, t_token **tokens)
{
	char	*buffer;
	int		len;
	t_token	*token;

	(*input)++;
	len = fn_quote_len(*input, '\"');
	buffer = (char *)malloc((len + 1) + sizeof(char));
	if (buffer == NULL)
		return (LEXER_ERR);
	fn_quote_cpy(input, buffer, '\"');
	if (**input == '\"')
		(*input)++;
	else
	{
		free(buffer);
		return (LEXER_ERR_DOUBLE_QUOTE);
	}
	token = fn_token_new(TOKEN_STRING_DOUBLE, buffer);
	free(buffer);
	if (token == NULL)
		return (LEXER_ERR);
	fn_token_add(tokens, token);
	return (fn_lexer_next_state(*input));
}
