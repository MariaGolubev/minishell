/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atof.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/18 10:18:10 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/11/18 18:29:35 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	decimal(float *outp, float *decimal_place, const char *str)
{
	while (ft_isdigit(*str))
	{
		*outp += *decimal_place * (float)(*str - '0');
		*decimal_place *= 0.1;
		str++;
	}
}

float	ft_atof(const char *str)
{
	int		sign;
	float	outp;
	float	decimal_place;

	sign = 1;
	outp = 0.0;
	decimal_place = 0.1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		sign = ',' - (int)*str++;
	while (ft_isdigit(*str))
	{
		outp = (outp * 10.0) + (float)(*str - '0');
		str++;
	}
	if (*str == '.')
		decimal(&outp, &decimal_place, ++str);
	return (outp * sign);
}
