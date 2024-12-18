/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_parser_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/07 13:25:29 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/10 23:47:09 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_ast_value	*fn_create_ast_value(t_token *token)
{
	if (!token)
		return (NULL);
	if (token->type == TOKEN_WORD || token->type == TOKEN_STRING_SINGLE
		|| token->type == TOKEN_ASSIGN
		|| token->type == TOKEN_BACKGROUND)
		return (fn_ast_value_new(VALUE_WORD, token->value));
	if (token->type == TOKEN_ESCAPE)
		return (fn_ast_value_new(VALUE_WORD, token->value + 1));
	if (token->type == TOKEN_STRING_DOUBLE)
		return (fn_ast_value_new(VALUE_WORD_DOUBLE_QUOTE, token->value));
	if (token->type == TOKEN_VARIABLE)
		return (fn_ast_value_new(VALUE_VARIABLE, token->value + 1));
	return (NULL);
}

int	fn_is_simple_token(t_token *token)
{
	if (!token)
		return (0);
	if (token->type == TOKEN_WORD || token->type == TOKEN_STRING_SINGLE
		|| token->type == TOKEN_STRING_DOUBLE || token->type == TOKEN_ESCAPE
		|| token->type == TOKEN_ASSIGN || token->type == TOKEN_SPACE
		|| token->type == TOKEN_VARIABLE
		|| token->type == TOKEN_BACKGROUND)
		return (1);
	return (0);
}

t_cmdline_state	fn_free_and_return(t_ast_value	*key,
							t_ast_value	*value, char **error)
{
	fn_ast_values_clean(&key);
	fn_ast_values_clean(&value);
	*error = "malloc error";
	return (CMDLINE_ERR);
}
