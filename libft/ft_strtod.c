/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtod.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/18 18:47:01 by maria         #+#    #+#                 */
/*   Updated: 2024/11/19 13:18:10 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

#define _HUGE_VAL 1.0e300 
#define _DBL_MAX 1.7976931348623157e308

static double	overflow(const char *str, char **endptr, int sign)
{
	errno = ERANGE;
	if (endptr)
		*endptr = (char *)str;
	return ((sign == 1) * _HUGE_VAL + (sign == -1) * -_HUGE_VAL);
}

static void	decimal(double *outp, double *decimal_place, const char **str)
{
	(*str)++;
	while (**str && ft_isdigit(**str))
	{
		*outp += *decimal_place * (**str - '0');
		*decimal_place *= 0.1;
		(*str)++;
	}
}

double	ft_strtod(const char *str, char **endptr)
{
	int		sign;
	double	outp;
	double	decimal_place;

	sign = 1;
	outp = 0.0;
	decimal_place = 0.1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		sign = ',' - *str++;
	while (*str && ft_isdigit(*str))
	{
		if (outp > (_DBL_MAX - (*str - '0')) / 10.0)
			return (overflow(str, endptr, sign));
		outp = outp * 10 + (*str++ - '0');
	}
	if (*str == '.')
		decimal(&outp, &decimal_place, &str);
	if (endptr)
		*endptr = (char *)str;
	return (outp * sign);
}
