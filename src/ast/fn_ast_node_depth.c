/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_ast_node_depth.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 14:20:22 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/10 14:21:28 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

int	fn_ast_node_depth(t_ast_node *head)
{
	int	depth;

	depth = 0;
	while (head)
	{
		head = head->right;
		depth++;
	}
	return (depth);
}
