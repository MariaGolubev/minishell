/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                           :+:    :+:           */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/09 10:25:14 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/10/29 16:16:48 by mgolubev       ########   odam.nl        */
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
		str[len - 1] = '0' + n % 10;
		n = n / 10;
		len--;
	}
	if (isminus)
		*str = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	len = f_numlen(n);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	return (f_itoa_str(n, str, len));
}
