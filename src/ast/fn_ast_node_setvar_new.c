/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_ast_node_setvar_new.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/02 19:00:57 by maria         #+#    #+#                 */
/*   Updated: 2024/12/03 21:36:56 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_ast_node	*fn_ast_node_setvar_new(t_ast_value *key, t_ast_value *values)
{
	t_ast_node	*node;

	node = fn_ast_node_new(AST_SET_VARIABLE);
	if (node == NULL)
		return (NULL);
	node->key = key;
	node->values = values;
	return (node);
}
