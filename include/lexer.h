/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lexer.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/28 18:28:29 by maria         #+#    #+#                 */
/*   Updated: 2024/12/16 12:10:26 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "token.h"

# define BUFFER_SIZE 1024
# define KEYS "|&=<>;\'\"$#\\"

# define LEXER_EXT_SUCCESS 0
# define LEXER_EXT_ERROR 1
# define LEXER_EXT_CRITICAL_ERROR 2

typedef enum e_lexer_state
{
	LEXER_START,
	LEXER_WORD,
	LEXER_PIPE,
	LEXER_AND,
	LEXER_ASSIGN,
	LEXER_REDIRECT,
	LEXER_SINGLE_QUOTE,
	LEXER_DOUBLE_QUOTE,
	LEXER_SEMICOLON,
	LEXER_VARIABLE,
	LEXER_COMMENT,
	LEXER_ESC,
	LEXER_ERR_SINGLE_QUOTE,
	LEXER_ERR_DOUBLE_QUOTE,
	LEXER_NL,
	LEXER_ERR,
	LEXER_EOF,
}	t_lexer_state_type;

typedef t_lexer_state_type	(*t_lexer_fn)(const char **input, t_token **tokens);

int					fn_lexer(const char *input, t_token **tokens);
t_lexer_state_type	fn_lexer_next_state(const char *input);
t_lexer_state_type	fn_lexer_start(const char **input, t_token **token);
t_lexer_state_type	fn_lexer_word(const char **input, t_token **token);
t_lexer_state_type	fn_lexer_redirect(const char **input, t_token **token);
t_lexer_state_type	fn_lexer_pipe_and_or(const char **input, t_token **token);
t_lexer_state_type	fn_lexer_semicolon(const char **input, t_token **token);
t_lexer_state_type	fn_lexer_single_quote(const char **input, t_token **token);
t_lexer_state_type	fn_lexer_double_quote(const char **input, t_token **token);
t_lexer_state_type	fn_lexer_escape(const char **input, t_token **token);
t_lexer_state_type	fn_lexer_and(const char **input, t_token **token);
t_lexer_state_type	fn_lexer_variable(const char **input, t_token **token);
t_lexer_state_type	fn_lexer_comment(const char **input, t_token **token);
t_lexer_state_type	fn_lexer_assign(const char **input, t_token **token);
t_lexer_state_type	fn_lexer_nl(const char **input, t_token **token);

#endif
