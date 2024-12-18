/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_ast_node_free.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/04 15:14:41 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/10 20:50:56 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static void	fn_ast_node_delone(t_ast_node **node)
{
	if (*node == NULL)
		return ;
	if ((*node)->key)
		fn_ast_values_clean(&(*node)->key);
	if ((*node)->values)
		fn_ast_values_clean(&(*node)->values);
	free(*node);
	*node = NULL;
}

void	fn_ast_node_clean(t_ast_node **head)
{
	if (*head == NULL)
		return ;
	if ((*head)->left)
		fn_ast_node_clean(&(*head)->left);
	if ((*head)->right)
		fn_ast_node_clean(&(*head)->right);
	fn_ast_node_delone(head);
}
