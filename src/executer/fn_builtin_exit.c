/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_builtin_exit.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/11 13:47:34 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/16 15:26:38 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

int	fn_buildin_exit(t_executer *exec, int argc, char **argv)
{
	int		exit_code;
	char	*endptr;

	endptr = NULL;
	printf("exit\n");
	if (argc == 1)
	{
		exec->isexit = 1;
		return (g_exit_code);
	}
	else if (argc > 2)
	{
		ft_putendl_fd("minishell: exit: too many arguments", 2);
		return (EXIT_FAILURE);
	}
	exit_code = ft_strtol(argv[1], &endptr, 10);
	if (errno == ERANGE || *endptr != '\0')
	{
		errno = 0;
		ft_putendl_fd("minishell: exit: numeric argument required", 2);
		exec->isexit = 1;
		return (2);
	}
	exec->isexit = 1;
	return (exit_code);
}
