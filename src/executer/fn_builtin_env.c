/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_builtin_env.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/12 17:18:39 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/17 12:30:04 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static void	fn_env_child(t_executer *exec)
{
	t_env_node	*global;

	dup2(exec->in_fd, STDIN_FILENO);
	dup2(exec->out_fd, STDOUT_FILENO);
	close(exec->in_fd);
	close(exec->out_fd);
	global = exec->envs->global_envs;
	while (global)
	{
		if (global->value)
			printf("%s=%s\n", global->key, global->value);
		global = global->next;
	}
	fn_executer_clean(exec);
	exit (EXIT_SUCCESS);
}

int	fn_builtin_env(t_executer *exec, int argc, char **argv)
{
	pid_t		pid;
	int			status;

	(void)argc;
	(void)argv;
	pid = fork();
	if (pid == -1)
		return (EXIT_FAILURE);
	else if (pid == 0)
		fn_env_child(exec);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}
