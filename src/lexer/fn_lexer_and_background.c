/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_lexer_and_background.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/28 20:17:07 by maria         #+#    #+#                 */
/*   Updated: 2024/12/09 11:48:32 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer_state_type	fn_lexer_and(const char **input, t_token **tokens)
{
	t_token	*token;

	if (ft_strncmp(*input, "&&", 2) == 0)
		token = fn_token_new(TOKEN_AND, "&&");
	else
		token = fn_token_new(TOKEN_BACKGROUND, "&");
	if (token == NULL)
		return (LEXER_ERR);
	fn_token_add(tokens, token);
	*input += ft_strlen(token->value);
	return (fn_lexer_next_state(*input));
}
