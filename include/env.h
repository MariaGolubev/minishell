/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   env.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/29 14:20:48 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/16 18:14:33 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include "libft.h"

typedef struct s_env_node
{
	char				*key;
	char				*value;
	struct s_env_node	*next;
}	t_env_node;

typedef struct s_envs
{
	t_env_node	*global_envs;
	t_env_node	*shel_env;
	t_env_node	*program_env;
	char		*status;
}	t_envs;

typedef enum e_scope
{
	GLOBAL,
	SHELL,
	PROGRAM,
}	t_scope;

char		*fn_env_node_get_value(t_env_node *env, const char *key);
void		fn_env_node_free(t_env_node **env);
t_env_node	*fn_env_node_new(const char *key, const char *value);
void		fn_env_node_append(t_env_node **head, t_env_node *new);
char		*fn_env_node_extract_key(char *key);
char		*fn_env_node_extract_value(char *value);
t_env_node	*fn_env_node_init(char **envg);
int			fn_env_node_get_size(t_env_node *env);
bool		fn_env_node_set(t_env_node *env,
				const char *key, const char *new_value);

t_envs		*fn_envs_new(char **envp);
void		fn_envs_clean_all(t_envs **envs);
char		**fn_env_node_to_array(t_env_node *env);
char		**fn_env_node_to_array(t_env_node *env);
char		*fn_envs_get_value(t_envs *envs, const char *key);
char		**fn_envs_to_array(t_envs *envs);
int			fn_envs_set_status(t_envs *envs, int status);
void		fn_envs_export(t_envs *envs, const char *key, const char *value);
t_env_node	*fn_env_node_take(t_env_node **head, const char *key);

#endif
