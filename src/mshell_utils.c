/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mshell_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/16 13:47:04 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/17 11:33:56 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_token(t_token *token)
{
	printf("Token Type: %2d, Value: '%s'\n", token->type, token->value);
}

static void	fn_init_map(char **map)
{
	map[AST_SEMICOLON] = "AST_SEMICOLON";
	map[AST_PIPE] = "AST_PIPE";
	map[AST_AND] = "AST_AND";
	map[AST_OR] = "AST_OR";
	map[AST_REDIRECT_OUT] = "AST_REDIRECT_OUT";
	map[AST_APPEND_OUT] = "AST_APPEND_OUT";
	map[AST_REDIRECT_IN] = "AST_REDIRECT_IN";
	map[AST_HEREDOC_START] = "AST_HEREDOC_START";
	map[AST_COMMAND] = "AST_COMMAND";
	map[AST_SET_VARIABLE] = "AST_SET_VARIABLE";
	map[AST_VALUES] = "AST_VALUES";
	map[AST_ARGUMENT] = "AST_ARGUMENT";
}

static t_ast_value	*fn_print_and_next(t_ast_value *value)
{
	printf("(%i)'%s' ", value->type, value->value);
	return (value->next);
}

void	print_ast_node(int depth, t_ast_node *node)
{
	char		*map[AST_ERR];
	t_ast_value	*key;
	t_ast_value	*value;

	fn_init_map(map);
	if (!node)
		return ;
	printf("%*sNode Type: %s", depth * 2, " ", map[node->type]);
	key = node->key;
	if (key != NULL)
		printf("\n%*sKeys: ", depth * 2, " ");
	while (key)
		key = fn_print_and_next(key);
	value = node->values;
	if (value != NULL)
		printf("\n%*sValues: ", depth * 2, " ");
	while (value)
		value = fn_print_and_next(value);
	printf("\n");
}
