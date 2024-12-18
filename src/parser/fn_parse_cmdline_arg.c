/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_parse_cmdline_arg.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/07 15:55:55 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/10 20:50:45 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_cmdline_state	fn_parse_cmdline_arg(t_cmdline *data, t_token **token)
{
	t_ast_value	*new;
	t_ast_value	*value;
	t_ast_node	*arg;

	value = NULL;
	while (*token && fn_is_simple_token(*token)
		&& (*token)->type != TOKEN_SPACE)
	{
		new = fn_create_ast_value(*token);
		if (new == NULL)
		{
			fn_ast_values_clean(&value);
			return (CMDLINE_ERR);
		}
		fn_ast_value_append(&value, new);
		*token = (*token)->next;
	}
	arg = fn_ast_node_argument_new(value);
	if (arg == NULL)
	{
		fn_ast_values_clean(&value);
		return (CMDLINE_ERR);
	}
	fn_ast_node_append(&data->cmd->right, arg);
	return (fn_parse_cmdline_next_state(data, token));
}
