/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_tokens_foreach.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 19:43:16 by maria         #+#    #+#                 */
/*   Updated: 2024/12/16 12:05:48 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void	fn_tokens_foreach(t_token *head, void (*fn)(t_token *token))
{
	while (head != NULL)
	{
		fn(head);
		head = head->next;
	}
}
