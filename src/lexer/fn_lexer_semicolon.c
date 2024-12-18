/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_lexer_semicolon.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/28 20:19:35 by maria         #+#    #+#                 */
/*   Updated: 2024/12/04 09:28:00 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer_state_type	fn_lexer_semicolon(const char **input, t_token **tokens)
{
	t_token	*token;

	token = fn_token_new(TOKEN_SEMICOLON, ";");
	if (token == NULL)
		return (LEXER_ERR);
	fn_token_add(tokens, token);
	(*input)++;
	return (fn_lexer_next_state(*input));
}
