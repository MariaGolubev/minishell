/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_tokens_clean.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 19:42:39 by maria         #+#    #+#                 */
/*   Updated: 2024/12/16 12:05:43 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void	fn_tokens_clean(t_token **head)
{
	t_token	*tmp;

	while (*head != NULL)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp->value);
		free(tmp);
	}
	*head = NULL;
}
