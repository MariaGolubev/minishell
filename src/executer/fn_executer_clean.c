/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_executer_clean.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 11:08:53 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/17 14:04:32 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

void	fn_executer_clean(t_executer *exec)
{
	if (exec->pwd)
	{
		free(exec->pwd);
		exec->pwd = NULL;
	}
	if (exec->envs)
		fn_envs_clean_all(&exec->envs);
	if (exec->ast)
		fn_ast_node_clean(&exec->ast);
	if (fn_is_file(HEREDOC_PATH))
	{
		unlink(HEREDOC_PATH);
	}
	fn_executer_close_fd(exec);
}
