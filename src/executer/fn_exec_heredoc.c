/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_exec_heredoc.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 12:00:29 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/17 13:33:02 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static void	fn_write_heredoc(char *limeter, int fd)
{
	char	*line;

	while (1)
	{
		line = readline("heredoc > ");
		if (line == NULL)
			break ;
		if (ft_strcmp(line, limeter) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, fd);
		free(line);
	}
}

static int	fn_create_heredoc(char *limeter)
{
	int		fd;

	fd = open(HEREDOC_PATH, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("heredoc");
		exit(EXIT_FAILURE);
	}
	fn_write_heredoc(limeter, fd);
	close(fd);
	return (open(HEREDOC_PATH, O_RDONLY));
}

static void	fn_heredoc_child(t_executer *exec, t_ast_node *ast)
{
	char	*limeter;

	fn_set_signal(HEREDOC);
	limeter = fn_ast_values_to_str(ast->values, exec->envs);
	if (limeter == NULL)
	{
		perror("limeter conversion");
		fn_executer_clean(exec);
		exit(EXIT_FAILURE);
	}
	close(exec->in_fd);
	exec->in_fd = fn_create_heredoc(limeter);
	free(limeter);
	exec->status = fn_exec_recursive(exec, ast->right);
	fn_executer_clean(exec);
	exit(exec->status);
}

int	fn_exec_heredoc(t_executer *exec, t_ast_node *ast)
{
	pid_t	pid;
	int		status;

	fn_set_signal(IGNORE);
	pid = fork();
	if (pid == -1)
		return (EXIT_FAILURE);
	else if (pid == 0)
		fn_heredoc_child(exec, ast);
	waitpid(pid, &status, 0);
	fn_set_signal(MAIN);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}
