/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_exec_semicolon.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 23:58:27 by maria         #+#    #+#                 */
/*   Updated: 2024/12/11 00:00:30 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	fn_exec_semicolon(t_executer *exec, t_ast_node *ast)
{
	exec->status = fn_exec_recursive(exec, ast->left);
	fn_envs_set_status(exec->envs, exec->status);
	exec->status = fn_exec_recursive(exec, ast->right);
	return (exec->status);
}
