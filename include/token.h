/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 19:40:25 by maria         #+#    #+#                 */
/*   Updated: 2024/12/16 12:10:42 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H
# define TOKEN_H
# include <stdlib.h>
# include "libft.h"

typedef enum e_token_type
{
	TOKEN_SPACE,
	TOKEN_WORD,
	TOKEN_ASSIGN,
	TOKEN_PIPE,
	TOKEN_REDIRECT_OUT,
	TOKEN_APPEND_OUT,
	TOKEN_REDIRECT_IN,
	TOKEN_HEREDOC_START,
	TOKEN_BACKGROUND,
	TOKEN_SEMICOLON,
	TOKEN_VARIABLE,
	TOKEN_STRING_DOUBLE,
	TOKEN_STRING_SINGLE,
	TOKEN_COMMENT,
	TOKEN_ESCAPE,
	TOKEN_OR,
	TOKEN_AND,
	TOKEN_NL,
	TOKEN_EOF,
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*value;
	struct s_token	*next;
}	t_token;

t_token			*fn_token_new(t_token_type type, const char *value);
t_token			*fn_token_last(t_token *head);
void			fn_token_add(t_token **head, t_token *new_token);
void			fn_tokens_clean(t_token **head);
void			fn_tokens_foreach(t_token *head, void (*fn)(t_token *token));

#endif
