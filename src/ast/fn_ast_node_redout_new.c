/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_ast_node_redout_new.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/03 21:18:04 by maria         #+#    #+#                 */
/*   Updated: 2024/12/03 21:18:47 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_ast_node	*fn_ast_node_redout_new(t_ast_value *file_name)
{
	t_ast_node	*node;

	node = fn_ast_node_new(AST_REDIRECT_OUT);
	if (node == NULL)
		return (NULL);
	node->values = file_name;
	return (node);
}
