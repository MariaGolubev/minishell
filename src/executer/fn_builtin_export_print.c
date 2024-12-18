/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_builtin_export_print.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/17 13:41:31 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/17 13:47:08 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static void	fn_export_print_child(t_executer *exec)
{
	t_env_node	*global;

	dup2(exec->in_fd, STDIN_FILENO);
	dup2(exec->out_fd, STDOUT_FILENO);
	close(exec->in_fd);
	close(exec->out_fd);
	global = exec->envs->global_envs;
	while (global)
	{
		ft_putstr_fd("declare -x ", 1);
		if (global->value)
			printf("%s=\"%s\"", global->key, global->value);
		else
			printf("%s", global->key);
		printf("\n");
		global = global->next;
	}
	fn_executer_clean(exec);
	exit(EXIT_SUCCESS);
}

int	fn_builtin_export_print(t_executer *exec)
{
	pid_t		pid;
	int			status;

	pid = fork();
	if (pid == -1)
		return (EXIT_FAILURE);
	else if (pid == 0)
		fn_export_print_child(exec);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}
