/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_mshell_parser.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 13:51:05 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/17 14:17:20 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell_state	fn_mshell_parser(t_minishell *mshell)
{
	int	status;

	status = fn_parser(mshell->tokens, &mshell->ast);
	if (mshell->tokens)
		fn_tokens_clean(&mshell->tokens);
	if (status == PARSER_EXT_ERROR)
		return (MINISHELL_READLINE);
	if (status == PARSER_EXT_CRITICAL_ERROR)
		return (MINISHELL_CLEAN);
	return (MINISHELL_EXECUTER);
}
