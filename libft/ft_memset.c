/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/08 10:08:28 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/10/14 16:26:02 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*orig;

	if (n == 0)
		return (dest);
	orig = dest;
	while (n--)
	{
		*(unsigned char *)dest++ = (unsigned char)c;
	}
	return (orig);
}
