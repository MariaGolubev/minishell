/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                        :+:    :+:           */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/08 10:08:24 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/10/12 13:53:07 by mgolubev       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!n || dest == src)
		return (dest);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (s > d)
		return (ft_memcpy(d, s, n));
	while (n)
	{
		n--;
		d[n] = s[n];
	}
	return (dest);
}
