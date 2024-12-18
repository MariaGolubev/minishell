/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_ast_value_append.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/02 18:41:46 by maria         #+#    #+#                 */
/*   Updated: 2024/12/06 19:13:50 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static t_ast_value	*fn_ast_value_last(t_ast_value *head)
{
	while (head->next != NULL)
		head = head->next;
	return (head);
}

void	fn_ast_value_append(t_ast_value **head, t_ast_value *new)
{
	if (*head == NULL)
		*head = new;
	else
		fn_ast_value_last(*head)->next = new;
}
