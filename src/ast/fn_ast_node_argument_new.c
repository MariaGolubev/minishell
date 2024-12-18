/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_ast_node_argument_new.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/03 21:26:43 by maria         #+#    #+#                 */
/*   Updated: 2024/12/03 21:30:43 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_ast_node	*fn_ast_node_argument_new(t_ast_value *arg)
{
	t_ast_node	*node;

	node = fn_ast_node_new(AST_ARGUMENT);
	if (node == NULL)
		return (NULL);
	node->values = arg;
	return (node);
}
