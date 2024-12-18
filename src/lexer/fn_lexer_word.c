/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_lexer_word.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/28 20:11:56 by maria         #+#    #+#                 */
/*   Updated: 2024/12/14 12:22:18 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	fn_world_len(const char *input)
{
	int	len;

	len = 0;
	while (*input && !ft_strchr(KEYS, *input) && !ft_isspace(*input))
	{
		len++;
		input++;
	}
	return (len);
}

static void	fn_word_cpy(const char **input, char *buffer)
{
	int		index;

	index = 0;
	while (**input && !ft_strchr(KEYS, **input) && !ft_isspace(**input))
	{
		buffer[index++] = **input;
		(*input)++;
	}
	buffer[index] = '\0';
}

t_lexer_state_type	fn_lexer_word(const char **input, t_token **tokens)
{
	char	*buffer;
	t_token	*token;

	if (**input == '$')
	{
		token = fn_token_new(TOKEN_WORD, "$");
		(*input)++;
	}
	else
	{
		buffer = (char *)malloc((fn_world_len(*input) + 1) * sizeof(char));
		if (buffer == NULL)
			return (LEXER_ERR);
		fn_word_cpy(input, buffer);
		token = fn_token_new(TOKEN_WORD, buffer);
		free(buffer);
	}
	if (token == NULL)
		return (LEXER_ERR);
	fn_token_add(tokens, token);
	return (fn_lexer_next_state(*input));
}
