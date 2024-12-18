/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_mshell_redline.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 13:49:42 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/18 21:41:58 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	fn_update_promt(char *promt, t_executer *exec)
{
	fn_set_signal(MAIN);
	ft_strlcpy(promt, BLUE, PROMT_SIZE);
	ft_strlcat(promt, exec->pwd, PROMT_SIZE);
	if (g_exit_code)
	{
		ft_strlcat(promt, RED, PROMT_SIZE);
		ft_strlcat(promt, " > ", PROMT_SIZE);
		ft_strlcat(promt, RESET, PROMT_SIZE);
	}
	else
	{
		ft_strlcat(promt, GREEN, PROMT_SIZE);
		ft_strlcat(promt, " > ", PROMT_SIZE);
		ft_strlcat(promt, RESET, PROMT_SIZE);
	}
}

t_minishell_state	fn_mshell_redline(t_minishell *mshell)
{
	fn_update_promt(mshell->promt, &mshell->exec);
	rl_on_new_line();
	mshell->input = readline(mshell->promt);
	if (errno == EINTR)
		errno = 0;
	if (mshell->input == NULL)
	{
		return (MINISHELL_CLEAN);
	}
	add_history(mshell->input);
	return (MINISHELL_LEXER);
}
