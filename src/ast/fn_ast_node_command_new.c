/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_ast_node_command_new.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/03 21:39:06 by maria         #+#    #+#                 */
/*   Updated: 2024/12/06 19:12:37 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_ast_node	*fn_ast_node_command_new(t_ast_value *cmd, t_ast_node *args)
{
	t_ast_node	*node;

	node = fn_ast_node_new(AST_COMMAND);
	if (node == NULL)
		return (NULL);
	node->key = cmd;
	node->right = args;
	return (node);
}
