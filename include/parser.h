/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/27 19:46:39 by maria         #+#    #+#                 */
/*   Updated: 2024/12/13 18:43:56 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "token.h"
# include "ast.h"

# define PARSER_EXT_SUCCESS 0
# define PARSER_EXT_ERROR 1
# define PARSER_EXT_CRITICAL_ERROR 2

typedef struct s_cmdline
{
	t_ast_node	*setenv;
	t_ast_node	*redirect;
	t_ast_node	*cmd;
	char		*error;
}	t_cmdline;

typedef enum e_cmdline_state
{
	CMDLINE_SETENV,
	CMDLINE_REDIRECT,
	CMDLINE_CMD,
	CMDLINE_ARG,
	CMDLINE_HEREDOC,
	CMDLINE_ERR,
	CMDLINE_DONE
}	t_cmdline_state;

typedef t_cmdline_state	(*t_cmdline_fn)(t_cmdline *data, t_token **tokens);

t_ast_value		*fn_create_ast_value(t_token *token);
int				fn_is_simple_token(t_token *token);

int				fn_parser(t_token *tokens, t_ast_node **ast);

t_cmdline_state	fn_parse_cmdline_setenv(t_cmdline *data, t_token **token);
t_cmdline_state	fn_parse_cmdline_redirect(t_cmdline *data, t_token **token);
t_cmdline_state	fn_parse_cmdline_cmd(t_cmdline *data, t_token **token);
t_cmdline_state	fn_parse_cmdline_arg(t_cmdline *data, t_token **token);
t_cmdline_state	fn_parse_cmdline_heredoc(t_cmdline *data, t_token **token);
t_cmdline_state	fn_parse_cmdline_arg(t_cmdline *data, t_token **token);
t_cmdline_state	fn_parse_cmdline_next_state(t_cmdline *data, t_token **token);

t_ast_node		*fn_parse_cmdline(t_token *tokens, char **error);
t_ast_node		*fn_parse_and_or(t_token *token, char **error);
t_ast_node		*fn_parse_pipe(t_token *token, char **error);
t_ast_node		*fn_parse_semicolon(t_token *token, char **error);

#endif
