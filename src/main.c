/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/26 14:36:27 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/18 21:27:35 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_code = 0;

int	main(int ac, char **av, char **envp)
{
	t_minishell			mshell;
	t_minishell_state	state;
	t_minishell_fn		map[MINISHELL_EXIT];

	((void)ac, (void)av);
	map[MINISHELL_READLINE] = fn_mshell_redline;
	map[MINISHELL_LEXER] = fn_mshell_lexer;
	map[MINISHELL_PARSER] = fn_mshell_parser;
	map[MINISHELL_EXECUTER] = fn_mshell_executer;
	map[MINISHELL_CLEAN] = fn_mshell_clean;
	state = fn_mshell_start(&mshell, envp);
	while (state != MINISHELL_EXIT)
	{
		fn_set_signal(MAIN);
		state = map[state](&mshell);
	}
	return (g_exit_code);
}
