/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_ast_value_free.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/04 15:16:25 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/10 20:50:45 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

static void	fn_ast_value_delone(t_ast_value **head)
{
	if (*head == NULL)
		return ;
	if ((*head)->value)
		free((*head)->value);
	free(*head);
	*head = NULL;
}

void	fn_ast_values_clean(t_ast_value	**head)
{
	t_ast_value	*tmp;

	while (*head)
	{
		tmp = (*head)->next;
		fn_ast_value_delone(head);
		*head = tmp;
	}
}
