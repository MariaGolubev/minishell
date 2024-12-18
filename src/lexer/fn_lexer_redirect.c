/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_lexer_redirect.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/28 20:13:43 by maria         #+#    #+#                 */
/*   Updated: 2024/12/06 12:49:09 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer_state_type	fn_lexer_redirect(const char **input, t_token **tokens)
{
	t_token	*token;

	if (ft_strncmp(*input, "<<", 2) == 0)
		token = fn_token_new(TOKEN_HEREDOC_START, "<<");
	else if (ft_strncmp(*input, ">>", 2) == 0)
		token = fn_token_new(TOKEN_APPEND_OUT, ">>");
	else if (**input == '<')
		token = fn_token_new(TOKEN_REDIRECT_IN, "<");
	else
		token = fn_token_new(TOKEN_REDIRECT_OUT, ">");
	if (token == NULL)
		return (LEXER_ERR);
	fn_token_add(tokens, token);
	*input += ft_strlen(token->value);
	return (fn_lexer_next_state(*input));
}
