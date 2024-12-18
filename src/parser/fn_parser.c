/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_parser.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/28 10:13:21 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/13 18:44:23 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include "parser.h"
#include "libft.h"

int	fn_parser(t_token *tokens, t_ast_node **ast)
{
	char	*error;

	if (tokens == NULL)
		return (0);
	error = NULL;
	*ast = fn_parse_semicolon(tokens, &error);
	if (errno != 0)
	{
		perror("minishell");
		return (PARSER_EXT_CRITICAL_ERROR);
	}
	if (error)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putendl_fd(error, 2);
		return (PARSER_EXT_ERROR);
	}
	return (PARSER_EXT_SUCCESS);
}
