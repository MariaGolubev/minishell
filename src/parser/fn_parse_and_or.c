/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_parse_and_or.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/07 13:29:37 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/13 13:45:11 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	fn_check_next_token(t_token *token)
{
	return (token->type != TOKEN_EOF
		&& token->type != TOKEN_AND
		&& token->type != TOKEN_OR
		&& token->type != TOKEN_SEMICOLON);
}

static t_ast_node	*fn_parse_and(t_token *start, t_token *token, char **error)
{
	t_ast_node	*left;
	t_ast_node	*right;

	left = fn_parse_pipe(start, error);
	right = fn_parse_and_or(token->next, error);
	if (left == NULL || right == NULL)
	{
		fn_ast_node_clean(&left);
		fn_ast_node_clean(&right);
		if (*error == NULL)
			*error = "parse error near '&&'";
		return (NULL);
	}
	return (fn_ast_node_and_new(left, right));
}

static t_ast_node	*fn_parse_or(t_token *start, t_token *token, char **error)
{
	t_ast_node	*left;
	t_ast_node	*right;

	left = fn_parse_pipe(start, error);
	right = fn_parse_and_or(token->next, error);
	if (left == NULL || right == NULL)
	{
		fn_ast_node_clean(&left);
		fn_ast_node_clean(&right);
		if (*error == NULL)
			*error = "parse error near '||'";
		return (NULL);
	}
	return (fn_ast_node_or_new(left, right));
}

t_ast_node	*fn_parse_and_or(t_token *token, char **error)
{
	t_token		*start;
	t_ast_node	*new;

	start = token;
	new = NULL;
	while (fn_check_next_token(token))
		token = token->next;
	if (token->type == TOKEN_AND)
	{
		new = fn_parse_and(start, token, error);
	}
	else if (token->type == TOKEN_OR)
	{
		new = fn_parse_or(start, token, error);
	}
	else
	{
		new = fn_parse_pipe(start, error);
	}
	return (new);
}
