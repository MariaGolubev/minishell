/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_mshell_clean.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 13:51:45 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/16 13:51:55 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell_state	fn_mshell_clean(t_minishell *mshell)
{
	if (mshell->input)
		free(mshell->input);
	if (mshell->tokens)
		fn_tokens_clean(&mshell->tokens);
	if (mshell->ast)
		fn_ast_node_clean(&mshell->ast);
	fn_executer_clean(&mshell->exec);
	return (MINISHELL_EXIT);
}
