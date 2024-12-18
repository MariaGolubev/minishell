/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   executer.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 10:53:16 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/17 15:31:10 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTER_H
# define EXECUTER_H
# include <termios.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <stdio.h>
# include <readline/readline.h>
# include "env.h"
# include "ast.h"

# define HEREDOC_PATH "/goinfre/heredoc"

typedef struct s_executer
{
	t_ast_node	*ast;
	t_envs		*envs;
	char		*pwd;
	int			status;
	int			isexit;
	int			in_fd;
	int			out_fd;
}	t_executer;

typedef enum e_signal
{
	MAIN,
	CHILD,
	PARENT,
	HEREDOC,
	IGNORE
}	t_signal;

typedef int	(*t_exec_fn)(t_executer *exec, t_ast_node *ast);

int		fn_buildin_exit(t_executer *exec, int argc, char **argv);
int		fn_buildin_pwd(t_executer *exec, int argc, char **argv);
int		fn_builtin_export_print(t_executer *exec);
int		fn_builtin_export(t_executer *exec, int argc, char **argv);
int		fn_builtin_cd(t_executer *exec, int argc, char **argv);
int		fn_builtin_env(t_executer *exec, int argc, char **argv);
int		fn_builtin_unset(t_executer *exec, int argc, char **argv);
int		fn_builtin_echo(t_executer *exec, int argc, char **argv);

int		fn_exec_recursive(t_executer *exec, t_ast_node *ast);
int		fn_exec_builtins_or_cmd(t_executer *exec, t_ast_node *ast);
int		fn_exec_cmd(t_executer *exec, char *cmd, char **args);
int		fn_exec_setvar(t_executer *exec, t_ast_node *ast);
int		fn_exec_redin(t_executer *exec, t_ast_node *ast);
int		fn_exec_redout(t_executer *exec, t_ast_node *ast);
int		fn_exec_append(t_executer *exec, t_ast_node *ast);
int		fn_exec_heredoc(t_executer *exec, t_ast_node *ast);
int		fn_exec_pipe(t_executer *exec, t_ast_node *ast);
int		fn_exec_and(t_executer *exec, t_ast_node *ast);
int		fn_exec_or(t_executer *exec, t_ast_node *ast);
int		fn_exec_semicolon(t_executer *exec, t_ast_node *ast);

int		fn_executer_init(t_executer *exec, char **envp);
void	fn_executer_clean(t_executer *exec);
void	fn_executer_close_fd(t_executer *exec);
int		fn_execute(t_executer *exec, t_ast_node *ast);

char	**fn_args_to_array(char *cmd, t_ast_node *args, t_envs *envs);
void	ft_free_array(char **args);
char	*fn_double_quote_to_str(const char *str, t_envs *envs);
char	*fn_ast_values_to_str(t_ast_value *values, t_envs *envs);
int		fn_array_len(char **array);
int		fn_is_file(const char *path);

int		fn_check_dir(char **args, char *abs);
int		fn_resolve(char **args, char **buf, int arg_ind);
void	fn_set_signal(int mode);

extern int	g_exit_code;

#endif
