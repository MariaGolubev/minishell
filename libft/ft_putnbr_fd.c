/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/09 14:38:29 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/17 12:12:30 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned char	f_numlen(int n)
{
	unsigned char	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*f_itoa_str(int n, char *str, unsigned char len)
{
	char			isminus;

	isminus = 0;
	if (n == -2147483648)
		return (ft_memcpy(str, "-2147483648", 11));
	if (n < 0)
	{
		isminus = 1;
		n = -n;
	}
	while (len)
	{
		str[--len] = '0' + n % 10;
		n = n / 10;
	}
	if (isminus)
		*str = '-';
	return (str);
}

ssize_t	ft_putnbr_fd(int n, int fd)
{
	unsigned int	len;
	char			str[11];

	len = f_numlen(n);
	f_itoa_str(n, str, len);
	return (write(fd, str, len));
}
