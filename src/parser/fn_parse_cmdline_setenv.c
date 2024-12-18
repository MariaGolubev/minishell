/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_parse_cmdline_setenv.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/06 10:26:10 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/10 20:50:45 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_cmdline_state	fn_parse_cmdline_setenv(t_cmdline *data, t_token **token)
{
	t_ast_value	*key;
	t_ast_value	*value;
	t_ast_value	*new;
	t_ast_node	*setenv;

	key = fn_ast_value_new(VALUE_WORD, (*token)->value);
	value = NULL;
	*token = (*token)->next->next;
	while (*token && fn_is_simple_token(*token)
		&& (*token)->type != TOKEN_SPACE)
	{
		new = fn_create_ast_value(*token);
		if (new == NULL)
			return ((fn_ast_values_clean(&value), CMDLINE_ERR));
		fn_ast_value_append(&value, new);
		*token = (*token)->next;
	}
	setenv = fn_ast_node_setvar_new(key, value);
	if (setenv == NULL)
		return ((fn_ast_values_clean(&value), CMDLINE_ERR));
	fn_ast_node_append(&data->setenv, setenv);
	return (fn_parse_cmdline_next_state(data, token));
}
