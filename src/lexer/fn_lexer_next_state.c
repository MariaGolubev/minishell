/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_lexer_next_state.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 18:01:38 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/14 12:53:06 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	fn_helper_with_quotes(char c)
{
	if (c == '\'')
		return (LEXER_SINGLE_QUOTE);
	else
		return (LEXER_DOUBLE_QUOTE);
}

static t_lexer_state_type	fn_helper_1(const char *input)
{
	if (*input == ';')
		return (LEXER_SEMICOLON);
	else if (*input == '#')
		return (LEXER_COMMENT);
	else
		return (LEXER_ASSIGN);
}

t_lexer_state_type	fn_lexer_next_state(const char *input)
{
	if (*input == '\0')
		return (LEXER_EOF);
	if (*input == '\n')
		return (LEXER_NL);
	else if (*input == '|')
		return (LEXER_PIPE);
	else if (ft_strchr("<>", *input))
		return (LEXER_REDIRECT);
	else if (ft_strchr("\'\"", *input))
		return (fn_helper_with_quotes(*input));
	else if (*input == '\\')
		return (LEXER_ESC);
	else if (ft_strchr(";#=", *input))
		return (fn_helper_1(input));
	else if (*input == '$' && input[1] != '\0'
		&& !ft_isdigit(input[1])
		&& (ft_isalnum(input[1]) || ft_strchr("_?", input[1])))
		return (LEXER_VARIABLE);
	else if (*input == '&')
		return (LEXER_AND);
	else if (ft_isspace(*input))
		return (LEXER_START);
	else
		return (LEXER_WORD);
}
