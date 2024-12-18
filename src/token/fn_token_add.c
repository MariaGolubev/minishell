/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_token_add.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 19:42:07 by maria         #+#    #+#                 */
/*   Updated: 2024/11/30 19:42:22 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

void	fn_token_add(t_token **head, t_token *new_token)
{
	if (*head == NULL)
		*head = new_token;
	else
		fn_token_last(*head)->next = new_token;
}
