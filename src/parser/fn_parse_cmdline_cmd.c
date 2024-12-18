/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_parse_cmdline_cmd.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/06 10:26:02 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/10 20:50:45 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_cmdline_state	fn_parse_cmdline_cmd(t_cmdline *data, t_token **token)
{
	t_ast_value	*value;
	t_ast_value	*new;

	value = NULL;
	while (*token && fn_is_simple_token(*token)
		&& (*token)->type != TOKEN_SPACE)
	{
		new = fn_create_ast_value(*token);
		if (new == NULL)
			return ((fn_ast_values_clean(&value), CMDLINE_ERR));
		fn_ast_value_append(&value, new);
		*token = (*token)->next;
	}
	data->cmd = fn_ast_node_command_new(value, NULL);
	if (data->cmd == NULL)
	{
		fn_ast_values_clean(&value);
		return (CMDLINE_ERR);
	}
	return (fn_parse_cmdline_next_state(data, token));
}
