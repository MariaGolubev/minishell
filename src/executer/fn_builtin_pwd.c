/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_builtin_pwd.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/11 14:29:41 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/17 11:52:30 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	fn_buildin_pwd(t_executer *exec, int argc, char **argv)
{
	pid_t	pid;
	int		status;

	(void)argc;
	(void)argv;
	pid = fork();
	if (pid == -1)
		return (EXIT_FAILURE);
	else if (pid == 0)
	{
		dup2(exec->in_fd, STDIN_FILENO);
		dup2(exec->out_fd, STDOUT_FILENO);
		close(exec->in_fd);
		close(exec->out_fd);
		ft_putendl_fd(exec->pwd, 1);
		fn_executer_clean(exec);
		exit (EXIT_SUCCESS);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}
