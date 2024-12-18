/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_exec_recursive.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 11:47:10 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/11 14:03:25 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	fn_exec_recursive(t_executer *exec, t_ast_node *ast)
{
	t_exec_fn	map[AST_ERR];

	if (ast == NULL)
		return (0);
	map[AST_COMMAND] = fn_exec_builtins_or_cmd;
	map[AST_SET_VARIABLE] = fn_exec_setvar;
	map[AST_REDIRECT_IN] = fn_exec_redin;
	map[AST_REDIRECT_OUT] = fn_exec_redout;
	map[AST_APPEND_OUT] = fn_exec_append;
	map[AST_HEREDOC_START] = fn_exec_heredoc;
	map[AST_PIPE] = fn_exec_pipe;
	map[AST_AND] = fn_exec_and;
	map[AST_OR] = fn_exec_or;
	map[AST_SEMICOLON] = fn_exec_semicolon;
	return (map[ast->type](exec, ast));
}
