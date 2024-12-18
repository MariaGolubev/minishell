/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_lexer_assign.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/29 10:53:21 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/09 11:48:42 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer_state_type	fn_lexer_assign(const char **input, t_token **tokens)
{
	t_token	*token;

	token = fn_token_new(TOKEN_ASSIGN, "=");
	if (token == NULL)
	{
		return (LEXER_ERR);
	}
	fn_token_add(tokens, token);
	(*input)++;
	return (fn_lexer_next_state(*input));
}
