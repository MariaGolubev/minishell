/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_exec_or.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 12:07:35 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/10 21:13:38 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	fn_exec_or(t_executer *exec, t_ast_node *ast)
{
	exec->status = fn_exec_recursive(exec, ast->left);
	fn_envs_set_status(exec->envs, exec->status);
	if (exec->status)
		return (fn_exec_recursive(exec, ast->right));
	return (exec->status);
}
