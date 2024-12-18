/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_parse_semicolon.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 23:49:19 by maria         #+#    #+#                 */
/*   Updated: 2024/12/14 12:58:17 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_ast_node	*fn_parse_semicolon(t_token *token, char **error)
{
	t_token		*start;
	t_ast_node	*left;
	t_ast_node	*right;

	start = token;
	while (token->type != TOKEN_EOF && token->type != TOKEN_SEMICOLON
		&& token->type != TOKEN_NL)
		token = token->next;
	if (token->type == TOKEN_SEMICOLON || token->type == TOKEN_NL)
	{
		left = fn_parse_and_or(start, error);
		right = fn_parse_semicolon(token->next, error);
		if (left == NULL || right == NULL)
		{
			fn_ast_node_clean(&left);
			fn_ast_node_clean(&right);
			if (*error == NULL)
				*error = "parse error near ';'";
			return (NULL);
		}
		return (fn_ast_node_semicolon_new(left, right));
	}
	else
		return (fn_parse_and_or(start, error));
	return (fn_ast_node_and_new(left, right));
}
