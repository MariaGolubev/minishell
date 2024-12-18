/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_ast_node_append.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/03 21:31:35 by maria         #+#    #+#                 */
/*   Updated: 2024/12/03 21:34:33 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static	t_ast_node	*fn_node_last(t_ast_node *head)
{
	while (head->right != NULL)
	{
		head = head->right;
	}
	return (head);
}

void	fn_ast_node_append(t_ast_node **head, t_ast_node *new)
{
	if (*head == NULL)
		*head = new;
	else
		fn_node_last(*head)->right = new;
}
