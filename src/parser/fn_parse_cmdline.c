/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_parse_cmdline.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/05 16:17:27 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/10 20:50:56 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	fn_data_init(t_cmdline *data)
{
	data->cmd = NULL;
	data->redirect = NULL;
	data->setenv = NULL;
	data->error = NULL;
}

static void	fn_data_free(t_cmdline *data)
{
	fn_ast_node_clean(&data->cmd);
	fn_ast_node_clean(&data->setenv);
	fn_ast_node_clean(&data->redirect);
}

static t_ast_node	*fn_data_cat(t_cmdline	*data)
{
	fn_ast_node_append(&data->redirect, data->cmd);
	fn_ast_node_append(&data->setenv, data->redirect);
	return (data->setenv);
}

static void	fn_init_map(t_cmdline_fn *map)
{
	map[CMDLINE_SETENV] = fn_parse_cmdline_setenv;
	map[CMDLINE_REDIRECT] = fn_parse_cmdline_redirect;
	map[CMDLINE_HEREDOC] = fn_parse_cmdline_heredoc;
	map[CMDLINE_CMD] = fn_parse_cmdline_cmd;
	map[CMDLINE_ARG] = fn_parse_cmdline_arg;
}

t_ast_node	*fn_parse_cmdline(t_token *tokens, char **error)
{
	t_cmdline		data;
	t_cmdline_fn	map[CMDLINE_DONE];
	t_cmdline_state	state;

	fn_data_init(&data);
	fn_init_map(map);
	state = fn_parse_cmdline_next_state(&data, &tokens);
	while (state != CMDLINE_DONE && state != CMDLINE_ERR)
	{
		state = map[state](&data, &tokens);
	}
	if (state == CMDLINE_ERR)
	{
		*error = data.error;
		fn_data_free(&data);
		return (NULL);
	}
	return (fn_data_cat(&data));
}
