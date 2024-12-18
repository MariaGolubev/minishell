/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_envs_set_status.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 17:20:12 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/10 21:10:31 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	fn_envs_set_status(t_envs *envs, int status)
{
	char	*new_status;

	new_status = ft_itoa(status);
	if (new_status == NULL)
		return (1);
	free(envs->status);
	envs->status = new_status;
	return (0);
}
