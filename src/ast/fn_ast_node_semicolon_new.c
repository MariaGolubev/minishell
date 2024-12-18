/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_ast_node_semicolon_new.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 23:54:36 by maria         #+#    #+#                 */
/*   Updated: 2024/12/10 23:55:04 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_ast_node	*fn_ast_node_semicolon_new(t_ast_node *left, t_ast_node *right)
{
	t_ast_node	*node;

	node = fn_ast_node_new(AST_SEMICOLON);
	if (node == NULL)
		return (NULL);
	node->left = left;
	node->right = right;
	return (node);
}
