/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_ast_node_foreach.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/02 19:17:13 by maria         #+#    #+#                 */
/*   Updated: 2024/12/06 19:13:41 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	fn_ast_foreach(int i, t_ast_node *node, t_ast_callback callback)
{
	if (!node)
		return ;
	callback(i, node);
	fn_ast_foreach(i + 1, node->left, callback);
	fn_ast_foreach(i + 1, node->right, callback);
}

void	fn_ast_node_foreach(t_ast_node *node, t_ast_callback callback)
{
	if (!node)
		return ;
	fn_ast_foreach(0, node, callback);
}
