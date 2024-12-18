/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_exec_builtins_or_cmd.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/11 14:01:05 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/17 15:33:07 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static int	fn_builtins(t_executer *exec, char *cmd, char **args)
{
	if (ft_strcmp(cmd, "exit") == 0)
		return (fn_buildin_exit(exec, fn_array_len(args), args));
	else if (ft_strcmp(cmd, "pwd") == 0)
		return (fn_buildin_pwd(exec, fn_array_len(args), args));
	else if (ft_strcmp(cmd, "export") == 0)
		return (fn_builtin_export(exec, fn_array_len(args), args));
	else if (ft_strcmp(cmd, "cd") == 0)
		return (fn_builtin_cd(exec, fn_array_len(args), args));
	else if (ft_strcmp(cmd, "env") == 0)
		return (fn_builtin_env(exec, fn_array_len(args), args));
	else if (ft_strcmp(cmd, "unset") == 0)
		return (fn_builtin_unset(exec, fn_array_len(args), args));
	else if (ft_strcmp(cmd, "echo") == 0)
		return (fn_builtin_echo(exec, fn_array_len(args), args));
	return (-1);
}

int	fn_exec_builtins_or_cmd(t_executer *exec, t_ast_node *ast)
{
	char	*cmd;
	char	**args;
	int		builtin_status;

	cmd = fn_ast_values_to_str(ast->key, exec->envs);
	if (cmd == NULL)
		return (EXIT_FAILURE);
	args = fn_args_to_array(cmd, ast->right, exec->envs);
	if (cmd == NULL)
		return (EXIT_FAILURE);
	builtin_status = fn_builtins(exec, cmd, args);
	if (builtin_status != -1)
	{
		exec->status = builtin_status;
		fn_env_node_set(exec->envs->global_envs, "_", cmd);
		ft_free_array(args);
		free(cmd);
		return (fn_envs_set_status(exec->envs, exec->status), exec->status);
	}
	fn_set_signal(PARENT);
	exec->status = fn_exec_cmd(exec, cmd, args);
	fn_env_node_set(exec->envs->global_envs, "_", cmd);
	ft_free_array(args);
	free(cmd);
	return (exec->status);
}
