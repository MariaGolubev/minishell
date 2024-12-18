/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_exec_pipe.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 12:01:36 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/17 10:59:55 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static void	fn_left_child(int *pipefd, t_executer *exec, t_ast_node *ast)
{
	close(pipefd[0]);
	close(exec->out_fd);
	exec->out_fd = pipefd[1];
	fn_set_signal(CHILD);
	exec->status = fn_exec_recursive(exec, ast->left);
	fn_executer_clean(exec);
	exit(exec->status);
}

static void	fn_right_child(int *pipefd, t_executer *exec, t_ast_node *ast)
{
	close(pipefd[1]);
	close(exec->in_fd);
	exec->in_fd = pipefd[0];
	fn_set_signal(CHILD);
	exec->status = fn_exec_recursive(exec, ast->right);
	fn_executer_clean(exec);
	exit(exec->status);
}

static int	fn_close_pipefd(int *pipefd)
{
	close(pipefd[0]);
	close(pipefd[1]);
	return (1);
}

int	fn_exec_pipe(t_executer *exec, t_ast_node *ast)
{
	pid_t	pid[2];
	int		pipefd[2];
	int		status;

	fn_set_signal(PARENT);
	if (pipe(pipefd) == -1)
		return (perror("pipe"), 1);
	pid[0] = fork();
	if (pid[0] == -1)
		return (perror("fork"), fn_close_pipefd(pipefd));
	if (pid[0] == 0)
		fn_left_child(pipefd, exec, ast);
	pid[1] = fork();
	if (pid[1] == -1)
		return (perror("fork"), fn_close_pipefd(pipefd));
	if (pid[1] == 0)
		fn_right_child(pipefd, exec, ast);
	fn_close_pipefd(pipefd);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], &status, 0);
	fn_set_signal(MAIN);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (1);
}
