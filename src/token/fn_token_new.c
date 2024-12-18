/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_token_new.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/30 19:40:03 by maria         #+#    #+#                 */
/*   Updated: 2024/11/30 19:41:22 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_token	*fn_token_new(t_token_type type, const char *value)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (new == NULL)
		return (NULL);
	new->type = type;
	new->value = NULL;
	new->next = NULL;
	if (value == NULL)
		return (new);
	new->value = ft_strdup(value);
	if (new->value == NULL)
	{
		free(new);
		return (NULL);
	}
	return (new);
}
