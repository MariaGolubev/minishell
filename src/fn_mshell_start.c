/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_mshell_start.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 13:49:11 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/16 13:49:20 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell_state	fn_mshell_start(t_minishell *mshell, char **envp)
{
	if (fn_executer_init(&mshell->exec, envp))
	{
		perror("minishell");
		return (MINISHELL_EXIT);
	}
	mshell->input = NULL;
	mshell->tokens = NULL;
	mshell->ast = NULL;
	return (MINISHELL_READLINE);
}
