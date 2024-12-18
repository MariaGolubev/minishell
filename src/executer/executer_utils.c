/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executer_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 14:12:33 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/17 14:04:56 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void	ft_free_array(char **args)
{
	size_t	i;

	if (args == NULL)
		return ;
	i = 0;
	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	fn_array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

char	**fn_args_to_array(char *cmd, t_ast_node *args, t_envs *envs)
{
	int		count;
	char	**argv;
	int		i;

	count = fn_ast_node_depth(args);
	argv = (char **)malloc((count + 2) * sizeof(char *));
	if (argv == NULL)
		return (NULL);
	argv[0] = ft_strdup(cmd);
	if (argv[0] == NULL)
		return (free(argv), NULL);
	i = 0;
	while (i < count && args)
	{
		argv[i + 1] = fn_ast_values_to_str(args->values, envs);
		i++;
		args = args->right;
	}
	argv[i + 1] = NULL;
	return (argv);
}

int	fn_is_file(const char *path)
{
	struct stat	path_stat;

	if (stat(path, &path_stat) != 0)
	{
		errno = 0;
		return (0);
	}
	return (S_ISREG(path_stat.st_mode));
}

void	fn_executer_close_fd(t_executer *exec)
{
	if (exec->in_fd >= 0)
	{
		close(exec->in_fd);
		exec->in_fd = -1;
	}
	if (exec->out_fd >= 0)
	{
		close(exec->out_fd);
		exec->out_fd = -1;
	}
}
