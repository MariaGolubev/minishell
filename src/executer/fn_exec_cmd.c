/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_exec_cmd.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 11:49:23 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/17 15:30:57 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static char	*fn_get_exec_path(char *cmd, t_envs *envs)
{
	char	**env_paths;
	char	*path;
	int		i;

	i = 0;
	env_paths = NULL;
	if (fn_envs_get_value(envs, "PATH") != NULL)
		env_paths = ft_split(fn_envs_get_value(envs, "PATH"), ':');
	else
		return (ft_strdup(cmd));
	if (env_paths == NULL)
		return (NULL);
	i = 0;
	while (env_paths != NULL && env_paths[i] != NULL)
	{
		path = ft_strjoin_with(env_paths[i], cmd, '/');
		if (path == NULL)
			return (ft_free_array(env_paths), NULL);
		if (access(path, X_OK) == 0)
			return (ft_free_array(env_paths), path);
		free(path);
		i++;
	}
	ft_free_array(env_paths);
	return (ft_strdup(cmd));
}

static int	fn_clean_and_exit(char *cmd, char *path, char **args, char **envp)
{
	if (cmd)
		free(cmd);
	if (path)
		free(path);
	ft_free_array(args);
	ft_free_array(envp);
	return (EXIT_FAILURE);
}

static int	fn_cmd_not_found(char *cmd, char *path, char **args, char **envp)
{
	ft_putstr_fd("minishell: command not found: ", 2);
	ft_putendl_fd(cmd, 2);
	fn_clean_and_exit(cmd, path, args, envp);
	return (127);
}

static void	fn_exec_child(t_executer *exec, char *cmd, char **args)
{
	char	*path;
	char	**envp;

	path = fn_get_exec_path(cmd, exec->envs);
	envp = fn_envs_to_array(exec->envs);
	if (!path || !envp)
		exit((fn_executer_clean(exec),
				fn_clean_and_exit(cmd, path, args, envp)));
	dup2(exec->in_fd, STDIN_FILENO);
	dup2(exec->out_fd, STDOUT_FILENO);
	close(exec->in_fd);
	close(exec->out_fd);
	execve(path, args, envp);
	if (errno == ENOENT)
		exit((fn_executer_clean(exec),
				fn_cmd_not_found(cmd, path, args, envp)));
	perror(cmd);
	exit((fn_executer_clean(exec), fn_clean_and_exit(cmd, path, args, envp)));
}

int	fn_exec_cmd(t_executer *exec, char *cmd, char **args)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		return (EXIT_FAILURE);
	else if (pid == 0)
	{
		fn_set_signal(CHILD);
		fn_exec_child(exec, cmd, args);
	}
	waitpid(pid, &status, 0);
	fn_set_signal(PARENT);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}
