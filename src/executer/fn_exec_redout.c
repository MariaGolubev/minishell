/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_exec_redout.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 11:56:26 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/17 14:10:40 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	fn_exec_redout(t_executer *exec, t_ast_node *ast)
{
	char	*file;
	int		fd;

	file = fn_ast_values_to_str(ast->values, exec->envs);
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open");
		free(file);
		return (EXIT_FAILURE);
	}
	close(exec->out_fd);
	exec->out_fd = fd;
	free(file);
	exec->status = fn_exec_recursive(exec, ast->right);
	close(exec->out_fd);
	exec->out_fd = dup(STDOUT_FILENO);
	return (exec->status);
}
