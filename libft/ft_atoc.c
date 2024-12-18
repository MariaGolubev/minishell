/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoc.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/18 10:58:23 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/11/18 20:18:00 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

double complex	ft_atoc(const char *str)
{
	double	real;
	double	imag;
	int		sign;

	real = ft_strtod(str, (char **)&str);
	imag = 0.0f;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		sign = ',' - (int)*str++;
		imag = ft_strtod(str, (char **)&str) * sign;
	}
	if (*str != 'i')
		imag = 0.0f;
	return (real + imag * I);
}
