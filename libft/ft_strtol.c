/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtol.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/18 18:46:45 by maria         #+#    #+#                 */
/*   Updated: 2024/11/18 19:56:14 by maria         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>

static	int	to_digit(char ch, int *digit)
{
	if (ft_isdigit(ch))
		*digit = ch - '0';
	else if (ft_islower(ch))
		*digit = ch - 'a' + 10;
	else if (ft_isupper(ch))
		*digit = ch - 'A' + 10;
	else
		return (1);
	return (0);
}

static long int	overflow(const char *str, char **endptr, int sign)
{
	errno = ERANGE;
	if (endptr)
		*endptr = (char *)str;
	return ((sign == 1) * LONG_MAX + (sign == -1) * LONG_MIN);
}

long int	ft_strtol(const char *str, char **endptr, int base)
{
	int		sign;
	long	outp;
	int		digit;

	sign = 1;
	outp = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		sign = ',' - (int)*str++;
	while (*str)
	{
		if (to_digit(*str, &digit) || digit >= base)
			break ;
		if (outp > (LONG_MAX - digit) / base)
			return (overflow(str, endptr, sign));
		outp = outp * base + digit;
		str++;
	}
	if (endptr)
		*endptr = (char *)str;
	return (outp * sign);
}
