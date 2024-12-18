/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_lexer.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/28 18:28:11 by maria         #+#    #+#                 */
/*   Updated: 2024/12/14 12:55:16 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	fn_set_eof(t_token **tokens)
{
	t_token	*token;

	token = fn_token_new(TOKEN_EOF, NULL);
	if (token == NULL)
		return (-1);
	fn_token_add(tokens, token);
	return (0);
}

static void	fn_init_map(t_lexer_fn *state_map)
{
	state_map[LEXER_START] = fn_lexer_start;
	state_map[LEXER_WORD] = fn_lexer_word;
	state_map[LEXER_ASSIGN] = fn_lexer_assign;
	state_map[LEXER_REDIRECT] = fn_lexer_redirect;
	state_map[LEXER_PIPE] = fn_lexer_pipe_and_or;
	state_map[LEXER_SEMICOLON] = fn_lexer_semicolon;
	state_map[LEXER_SINGLE_QUOTE] = fn_lexer_single_quote;
	state_map[LEXER_DOUBLE_QUOTE] = fn_lexer_double_quote;
	state_map[LEXER_ESC] = fn_lexer_escape;
	state_map[LEXER_AND] = fn_lexer_and;
	state_map[LEXER_VARIABLE] = fn_lexer_variable;
	state_map[LEXER_COMMENT] = fn_lexer_comment;
	state_map[LEXER_NL] = fn_lexer_nl;
}

int	fn_lexer(const char *input, t_token **tokens)
{
	t_lexer_fn			state_map[LEXER_EOF];
	t_lexer_state_type	state;

	fn_init_map(state_map);
	state = fn_lexer_next_state(input);
	while (state != LEXER_EOF && state != LEXER_ERR
		&& state != LEXER_ERR_SINGLE_QUOTE && state != LEXER_ERR_DOUBLE_QUOTE)
	{
		state = state_map[state](&input, tokens);
	}
	if (fn_set_eof(tokens) || state == LEXER_ERR)
	{
		perror("minishell");
		return (fn_tokens_clean(tokens), LEXER_EXT_CRITICAL_ERROR);
	}
	else if (state == LEXER_ERR_SINGLE_QUOTE || state == LEXER_ERR_DOUBLE_QUOTE)
	{
		fn_tokens_clean(tokens);
		if (state == LEXER_ERR_SINGLE_QUOTE)
			ft_putendl_fd("minishell : unclosed single quote!", 2);
		else
			ft_putendl_fd("minishell : unclosed double quote!", 2);
		return (LEXER_EXT_ERROR);
	}
	return (LEXER_EXT_SUCCESS);
}
