/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_parse_pipe.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/07 13:29:40 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/13 13:43:41 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	fn_check_next_token(t_token *token)
{
	return (token->type != TOKEN_EOF
		&& token->type != TOKEN_PIPE
		&& token->type != TOKEN_AND
		&& token->type != TOKEN_OR
		&& token->type != TOKEN_SEMICOLON);
}

t_ast_node	*fn_parse_pipe(t_token *token, char **error)
{
	t_token		*start;
	t_ast_node	*left;
	t_ast_node	*right;

	start = token;
	while (fn_check_next_token(token))
		token = token->next;
	if (token->type == TOKEN_PIPE)
	{
		left = fn_parse_cmdline(start, error);
		right = fn_parse_pipe(token->next, error);
		if (left == NULL || right == NULL)
		{
			fn_ast_node_clean(&left);
			fn_ast_node_clean(&right);
			if (*error == NULL)
				*error = "parse error near '|'";
			return (NULL);
		}
		return (fn_ast_node_pipe_new(left, right));
	}
	else
		return (fn_parse_cmdline(start, error));
	return (NULL);
}
