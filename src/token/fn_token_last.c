/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_token_last.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 19:41:40 by maria         #+#    #+#                 */
/*   Updated: 2024/11/30 19:41:55 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_token	*fn_token_last(t_token *head)
{
	while (head != NULL && head->next != NULL)
		head = head->next;
	return (head);
}
