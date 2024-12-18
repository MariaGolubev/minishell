/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_exec_setvar.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 11:51:44 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/16 18:09:36 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static int	fn_iscmd(t_ast_node *ast)
{
	while (ast)
	{
		if (ast->type == AST_COMMAND)
			return (1);
		ast = ast->right;
	}
	return (0);
}

static int	fn_is_key(t_env_node *env, const char *key)
{
	while (env)
	{
		if (ft_strcmp(env->key, key) == 0)
			return (1);
		env = env->next;
	}
	return (0);
}

static bool	fn_exec_env_update(t_executer *exec,
			const char *key, const char *value)
{
	if (fn_is_key(exec->envs->shel_env, key))
		return (fn_env_node_set(exec->envs->shel_env, key, value));
	return (fn_env_node_set(exec->envs->global_envs, key, value));
}

int	fn_exec_setvar(t_executer *exec, t_ast_node *ast)
{
	char	*key;
	char	*value;
	bool	flag;

	value = NULL;
	key = fn_ast_values_to_str(ast->key, exec->envs);
	if (key == NULL)
		return (EXIT_FAILURE);
	value = fn_ast_values_to_str(ast->values, exec->envs);
	if (value == NULL)
		value = ft_calloc(1, sizeof(char));
	if (value == NULL)
		return (free(key), EXIT_FAILURE);
	if (fn_iscmd(ast))
		flag = fn_env_node_set(exec->envs->program_env, key, value);
	else
		flag = fn_exec_env_update(exec, key, value);
	(free(key), free(value));
	if (!flag)
	{
		perror("malloc");
		return (EXIT_FAILURE);
	}
	return (fn_exec_recursive(exec, ast->right));
}
