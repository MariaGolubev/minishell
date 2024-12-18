/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cd_utils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/12 15:30:48 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/16 11:54:46 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static int	fn_deduct(char **split, int index, char *str, char delim)
{
	char	*last_delim;
	int		count;

	count = 0;
	while (split[index] && !ft_strcmp(split[index], ".."))
	{
		count++;
		last_delim = ft_strrchr(str, delim);
		if (last_delim == str)
		{
			str[1] = '\0';
			return (count);
		}
		else if (last_delim)
			*last_delim = '\0';
		else
			return (count);
		index++;
	}
	return (count);
}

static int	fn_appen_with_con(char **left, char connector, char *right)
{
	char	*new;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(*left);
	len2 = 0;
	if (right)
		len2 = ft_strlen(right);
	new = malloc(sizeof(char) * (len1 + len2 + (connector != 0) + 1));
	if (!new)
		return (1);
	ft_strlcpy(new, *left, len1 + 1);
	if (connector != 0)
		new[len1] = connector;
	if (len2)
		ft_strlcpy(new + len1 + (connector != 0), right, len2 + 1);
	new[len1 + len2 + (connector != 0)] = '\0';
	if (*left)
		(free(*left), *left = NULL);
	*left = new;
	return (0);
}

static int	fn_append_helper(char **args, char **buf, char **split, int i)
{
	char	con;

	con = '/';
	(void)args;
	if (!ft_strcmp(*buf, "/"))
		con = 0;
	if (fn_appen_with_con(buf, con, split[i]))
		return (printf("malloc failed"));
	if (split[i + 1] && access(*buf, F_OK) < 0)
		return (1);
	return (0);
}

int	fn_resolve(char **args, char **buf, int arg_ind)
{
	char	**split;
	int		i;

	split = ft_split(args[arg_ind], '/');
	if (!split)
		return (printf("malloc failed"));
	i = -1;
	while (split[++i])
	{
		if (!ft_strcmp(split[i], "."))
			continue ;
		else if (!ft_strcmp(split[i], ".."))
			i += fn_deduct(split, i, *buf, '/') - 1;
		else if (fn_append_helper(args, buf, split, i))
			return (perror("cd:hehe"), 1);
	}
	ft_free_array(split);
	return (0);
}

int	fn_check_dir(char **args, char *abs)
{
	struct stat	info;

	(void)args;
	if (stat(abs, &info) == -1)
	{
		if (errno == ENOENT)
			ft_putendl_fd("minishell: cd: no such file or directory", 2);
		else
			ft_putendl_fd("minishell: cd: permission denied", 2);
	}
	else if ((info.st_mode & S_IFMT) != S_IFDIR)
		ft_putendl_fd("minishell: cd: not a directory", 2);
	else
		return (0);
	free(abs);
	return (1);
}
