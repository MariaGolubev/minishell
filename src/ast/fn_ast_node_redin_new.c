/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_ast_node_redin_new.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/02 20:04:56 by maria         #+#    #+#                 */
/*   Updated: 2024/12/02 20:37:49 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_ast_node	*fn_ast_node_redin_new(t_ast_value *file_name)
{
	t_ast_node	*node;

	node = fn_ast_node_new(AST_REDIRECT_IN);
	if (node == NULL)
		return (NULL);
	node->values = file_name;
	return (node);
}
