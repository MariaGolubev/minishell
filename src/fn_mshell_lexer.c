/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_mshell_lexer.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 13:50:42 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/17 14:17:13 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell_state	fn_mshell_lexer(t_minishell *mshell)
{
	int	status;

	status = fn_lexer(mshell->input, &mshell->tokens);
	if (mshell->input)
	{
		free(mshell->input);
		mshell->input = NULL;
	}
	if (status == LEXER_EXT_ERROR)
		return (MINISHELL_READLINE);
	if (status == LEXER_EXT_CRITICAL_ERROR)
		return (MINISHELL_CLEAN);
	return (MINISHELL_PARSER);
}
