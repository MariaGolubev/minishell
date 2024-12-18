/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_exec_and.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 12:03:14 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/10 21:12:56 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	fn_exec_and(t_executer *exec, t_ast_node *ast)
{
	int	res;

	res = fn_exec_recursive(exec, ast->left);
	if (errno != 0)
		return (res);
	if (res == 0)
		return (fn_exec_recursive(exec, ast->right));
	return (res);
}
