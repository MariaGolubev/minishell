/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_ast_node_and_new.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/06 17:44:21 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/06 17:45:47 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_ast_node	*fn_ast_node_and_new(t_ast_node *left, t_ast_node *right)
{
	t_ast_node	*node;

	node = fn_ast_node_new(AST_AND);
	if (node == NULL)
		return (NULL);
	node->left = left;
	node->right = right;
	return (node);
}
