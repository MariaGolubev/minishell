/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_builtin_echo.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/13 14:03:48 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/17 12:28:55 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static int	fn_check_ommit(char **args, int *i)
{
	int	ret;
	int	j;

	ret = 0;
	while (args[++(*i)])
	{
		j = 0;
		if (args[*i][j] == '-' && args[*i][j + 1] == 'n')
		{
			while (args[*i][++j] == 'n')
				;
			if (!args[*i][j])
				ret = 1;
			else
				break ;
		}
		else
			break ;
	}
	return (ret);
}

static void	fn_echo_child(t_executer *exec, char **argv)
{
	int		ommit;
	int		i;

	i = 0;
	dup2(exec->in_fd, STDIN_FILENO);
	dup2(exec->out_fd, STDOUT_FILENO);
	close(exec->in_fd);
	close(exec->out_fd);
	ommit = fn_check_ommit(argv, &i);
	while (argv[i])
	{
		ft_putstr_fd(argv[i], 1);
		if (argv[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (ommit == 0)
		ft_putchar_fd('\n', 1);
	fn_executer_clean(exec);
	exit (EXIT_SUCCESS);
}

int	fn_builtin_echo(t_executer *exec, int argc, char **argv)
{
	pid_t	pid;
	int		status;

	(void)argc;
	pid = fork();
	if (pid == -1)
		return (EXIT_FAILURE);
	else if (pid == 0)
		fn_echo_child(exec, argv);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}
