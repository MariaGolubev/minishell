/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_execute.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 11:14:44 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/17 14:17:36 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	fn_execute(t_executer *exec, t_ast_node *ast)
{
	struct termios	attributes;

	if (ast == NULL)
		return (EXIT_SUCCESS);
	tcgetattr(STDOUT_FILENO, &attributes);
	exec->ast = ast;
	exec->status = fn_exec_recursive(exec, ast);
	fn_envs_set_status(exec->envs, exec->status);
	exec->ast = NULL;
	tcsetattr(STDERR_FILENO, TCSAFLUSH, &attributes);
	return (exec->status);
}
