/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_mshell_executer.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 13:51:30 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/17 14:17:03 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell_state	fn_mshell_executer(t_minishell *mshell)
{
	fn_envs_set_status(mshell->exec.envs, g_exit_code);
	g_exit_code = fn_execute(&mshell->exec, mshell->ast);
	fn_set_signal(MAIN);
	fn_ast_node_clean(&mshell->ast);
	if (mshell->exec.isexit)
		return (MINISHELL_CLEAN);
	return (MINISHELL_READLINE);
}
