/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_parse_cmdline_heredoc.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/07 13:41:45 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/10 20:50:45 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_ast_value	*fn_create_ast_value_for_heredoc(t_token *token)
{
	if (!token)
		return (NULL);
	if (token->type == TOKEN_WORD || token->type == TOKEN_STRING_SINGLE
		|| token->type == TOKEN_ASSIGN)
		return (fn_ast_value_new(VALUE_WORD, token->value));
	if (token->type == TOKEN_ESCAPE)
		return (fn_ast_value_new(VALUE_WORD, token->value + 1));
	if (token->type == TOKEN_STRING_DOUBLE)
		return (fn_ast_value_new(VALUE_WORD, token->value));
	if (token->type == TOKEN_VARIABLE)
		return (fn_ast_value_new(VALUE_WORD, token->value));
	return (NULL);
}

t_cmdline_state	fn_parse_cmdline_heredoc(t_cmdline *data, t_token **token)
{
	t_ast_value		*value;
	t_ast_value		*new;
	t_ast_node		*heredoc;

	value = NULL;
	*token = (*token)->next;
	while (*token && (*token)->type == TOKEN_SPACE)
		*token = (*token)->next;
	while (*token && fn_is_simple_token(*token)
		&& (*token)->type != TOKEN_SPACE)
	{
		new = fn_create_ast_value_for_heredoc(*token);
		if (new == NULL)
			return ((fn_ast_values_clean(&value), CMDLINE_ERR));
		fn_ast_value_append(&value, new);
		*token = (*token)->next;
	}
	if (value == NULL)
		return (fn_ast_values_clean(&value),
			data->error = "limiter not found", CMDLINE_ERR);
	heredoc = fn_ast_node_heredoc_new(value);
	if (heredoc == NULL)
		return ((fn_ast_values_clean(&value), CMDLINE_ERR));
	fn_ast_node_append(&data->redirect, heredoc);
	return (fn_parse_cmdline_next_state(data, token));
}
