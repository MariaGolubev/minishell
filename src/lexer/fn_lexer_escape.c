/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_lexer_escape.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/28 20:16:35 by maria         #+#    #+#                 */
/*   Updated: 2024/12/09 11:47:44 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer_state_type	fn_lexer_escape(const char **input, t_token **tokens)
{
	t_token	*token;
	char	buffer[3];
	int		index;

	index = 0;
	while (index < 2 && **input)
	{
		buffer[index] = **input;
		index++;
		(*input)++;
	}
	buffer[index] = '\0';
	token = fn_token_new(TOKEN_ESCAPE, buffer);
	if (token == NULL)
		return (LEXER_ERR);
	fn_token_add(tokens, token);
	return (fn_lexer_next_state(*input));
}
