/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_ast_node_heredoc_new.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/07 14:38:14 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/07 14:39:48 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_ast_node	*fn_ast_node_heredoc_new(t_ast_value *limiter)
{
	t_ast_node	*node;

	node = fn_ast_node_new(AST_HEREDOC_START);
	if (node == NULL)
		return (NULL);
	node->values = limiter;
	return (node);
}
