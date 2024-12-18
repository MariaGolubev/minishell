/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_lexer_pipe_or.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/28 20:12:57 by maria         #+#    #+#                 */
/*   Updated: 2024/12/14 12:56:42 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer_state_type	fn_lexer_pipe_and_or(const char **input, t_token **tokens)
{
	t_token	*token;

	if (ft_strncmp(*input, "||", 2) == 0)
		token = fn_token_new(TOKEN_OR, "||");
	else
		token = fn_token_new(TOKEN_PIPE, "|");
	if (token == NULL)
	{
		return (LEXER_ERR);
	}
	fn_token_add(tokens, token);
	*input += ft_strlen(token->value);
	return (fn_lexer_next_state(*input));
}
