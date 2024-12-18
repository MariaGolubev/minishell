/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_executer_init.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 11:00:22 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/17 14:11:39 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	fn_executer_init(t_executer *exec, char **envp)
{
	exec->ast = NULL;
	exec->status = 0;
	exec->isexit = 0;
	exec->in_fd = dup(STDIN_FILENO);
	if (exec->in_fd == -1)
		return (EXIT_FAILURE);
	exec->out_fd = dup(STDOUT_FILENO);
	if (exec->out_fd == -1)
		return (close(exec->in_fd), EXIT_FAILURE);
	exec->envs = fn_envs_new(envp);
	if (exec->envs == NULL)
		return (EXIT_FAILURE);
	if (fn_env_node_get_value(exec->envs->global_envs, "PWD"))
		exec->pwd = ft_strdup(fn_env_node_get_value(exec->envs->global_envs,
					"PWD"));
	else
		exec->pwd = getcwd(NULL, 0);
	if (exec->pwd == NULL)
	{
		fn_envs_clean_all(&exec->envs);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
