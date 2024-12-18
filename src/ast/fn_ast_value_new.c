/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_ast_value_new.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/02 18:34:14 by maria         #+#    #+#                 */
/*   Updated: 2024/12/06 19:13:59 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"
#include "libft.h"

t_ast_value	*fn_ast_value_new(t_ast_value_type type, const char *value)
{
	t_ast_value	*new;

	new = (t_ast_value *)malloc(sizeof(t_ast_value));
	if (new == NULL)
		return (NULL);
	new->next = NULL;
	new->type = type;
	new->value = ft_strdup(value);
	if (new->value == NULL)
	{
		free(new);
		return (NULL);
	}
	return (new);
}
