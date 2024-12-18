/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_parse_cmdline_redirect.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/06 10:26:08 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/10 20:50:45 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	fn_append(t_token_type redirect_type,
	t_ast_value *value, t_cmdline *data)
{
	t_ast_node	*new;

	new = NULL;
	if (redirect_type == TOKEN_REDIRECT_IN)
		new = fn_ast_node_redin_new(value);
	if (redirect_type == TOKEN_REDIRECT_OUT)
		new = fn_ast_node_redout_new(value);
	else if (redirect_type == TOKEN_APPEND_OUT)
		new = fn_ast_node_append_new(value);
	if (new == NULL)
		return (1);
	fn_ast_node_append(&data->redirect, new);
	return (0);
}

t_cmdline_state	fn_parse_cmdline_redirect(t_cmdline *data, t_token **token)
{
	t_token_type	redirect_type;
	t_ast_value		*value;
	t_ast_value		*new;

	redirect_type = (*token)->type;
	*token = (*token)->next;
	value = NULL;
	while (*token && (*token)->type == TOKEN_SPACE)
		*token = (*token)->next;
	while (*token && fn_is_simple_token(*token)
		&& (*token)->type != TOKEN_SPACE)
	{
		new = fn_create_ast_value(*token);
		if (new == NULL)
			return ((fn_ast_values_clean(&value), CMDLINE_ERR));
		fn_ast_value_append(&value, new);
		*token = (*token)->next;
	}
	if (value == NULL)
		return (
			(data->error = "file name not found afte redirect!", CMDLINE_ERR));
	if (fn_append(redirect_type, value, data))
		return ((fn_ast_values_clean(&value), CMDLINE_ERR));
	return (fn_parse_cmdline_next_state(data, token));
}
