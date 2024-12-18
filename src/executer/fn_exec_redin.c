/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_exec_redin.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 11:54:54 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/17 14:10:21 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	fn_exec_redin(t_executer *exec, t_ast_node *ast)
{
	char	*file;
	int		fd;

	file = fn_ast_values_to_str(ast->values, exec->envs);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(file);
		free(file);
		return (EXIT_FAILURE);
	}
	close(exec->in_fd);
	exec->in_fd = fd;
	free(file);
	exec->status = fn_exec_recursive(exec, ast->right);
	close(exec->in_fd);
	exec->in_fd = dup(STDIN_FILENO);
	return (exec->status);
}
