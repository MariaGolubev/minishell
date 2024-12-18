/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_lexer_nl.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/14 12:54:03 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/14 13:04:45 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer_state_type	fn_lexer_nl(const char **input, t_token **tokens)
{
	t_token	*token;

	token = fn_token_new(TOKEN_NL, "NL");
	if (token == NULL)
	{
		return (LEXER_ERR);
	}
	fn_token_add(tokens, token);
	(*input)++;
	return (fn_lexer_next_state(*input));
}
