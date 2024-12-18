/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_lexer_start.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/28 20:10:47 by maria         #+#    #+#                 */
/*   Updated: 2024/12/09 12:04:49 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	fn_space_len(const char *input)
{
	int	len;

	len = 0;
	while (ft_isspace(*input))
	{
		input++;
		len++;
	}
	return (len);
}

t_lexer_state_type	fn_lexer_start(const char **input, t_token **tokens)
{
	char	*buffer;
	int		len;
	int		index;
	t_token	*token;

	index = 0;
	len = fn_space_len(*input);
	buffer = (char *)malloc((len + 1) * sizeof(char));
	if (buffer == NULL)
		return (LEXER_ERR);
	while (ft_isspace(**input))
	{
		buffer[index++] = **input;
		(*input)++;
	}
	buffer[index] = '\0';
	token = fn_token_new(TOKEN_SPACE, buffer);
	free(buffer);
	if (token == NULL)
		return (LEXER_ERR);
	fn_token_add(tokens, token);
	return (fn_lexer_next_state(*input));
}
