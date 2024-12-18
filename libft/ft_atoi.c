/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/08 14:08:53 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/11/18 19:00:36 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	outp;

	sign = 1;
	outp = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		sign = ',' - (int)*str++;
	while (ft_isdigit(*str))
	{
		outp = (outp * 10) + (int)(*str - '0');
		str++;
	}
	return (outp * sign);
}
