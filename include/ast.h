/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ast.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/02 09:41:51 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/10 23:53:59 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H
# include <stdlib.h>

typedef enum e_ast_type
{
	AST_PIPE,
	AST_SEMICOLON,
	AST_AND,
	AST_OR,
	AST_REDIRECT_OUT,
	AST_APPEND_OUT,
	AST_REDIRECT_IN,
	AST_HEREDOC_START,
	AST_COMMAND,
	AST_SET_VARIABLE,
	AST_VALUES,
	AST_ARGUMENT,
	AST_ERR,
}	t_ast_type;

typedef enum e_ast_value_type
{
	VALUE_WORD,
	VALUE_WORD_DOUBLE_QUOTE,
	VALUE_VARIABLE,
}	t_ast_value_type;

typedef struct s_ast_value
{
	t_ast_value_type	type;
	char				*value;
	struct s_ast_value	*next;
}	t_ast_value;

typedef struct s_ast_node
{
	t_ast_type			type;
	t_ast_value			*key;
	t_ast_value			*values;
	struct s_ast_node	*left;
	struct s_ast_node	*right;
}	t_ast_node;

typedef void	(*t_ast_callback)(int i, t_ast_node *node);

void		fn_ast_node_foreach(t_ast_node *node, t_ast_callback callback);
void		fn_ast_node_append(t_ast_node **head, t_ast_node *new);
void		fn_ast_node_clean(t_ast_node **head);
int			fn_ast_node_depth(t_ast_node *head);
t_ast_node	*fn_ast_node_new(t_ast_type type);
t_ast_node	*fn_ast_node_setvar_new(t_ast_value *key, t_ast_value *values);
t_ast_node	*fn_ast_node_redin_new(t_ast_value *file_name);
t_ast_node	*fn_ast_node_redout_new(t_ast_value *file_name);
t_ast_node	*fn_ast_node_append_new(t_ast_value *file_name);
t_ast_node	*fn_ast_node_pipe_new(t_ast_node *left, t_ast_node *right);
t_ast_node	*fn_ast_node_and_new(t_ast_node *left, t_ast_node *right);
t_ast_node	*fn_ast_node_or_new(t_ast_node *left, t_ast_node *right);
t_ast_node	*fn_ast_node_semicolon_new(t_ast_node *left, t_ast_node *right);
t_ast_node	*fn_ast_node_argument_new(t_ast_value *arg);
t_ast_node	*fn_ast_node_command_new(t_ast_value *cmd, t_ast_node *args);
t_ast_node	*fn_ast_node_heredoc_new(t_ast_value *limiter);

t_ast_value	*fn_ast_value_new(t_ast_value_type type, const char *value);
void		fn_ast_value_append(t_ast_value **head, t_ast_value *new);
void		fn_ast_values_clean(t_ast_value **head);

#endif
