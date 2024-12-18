/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/08 10:08:18 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/10/11 13:53:44 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*orig;

	if (!n || dest == src)
		return (dest);
	orig = dest;
	while (n--)
		*(unsigned char *)dest++ = *(unsigned char *)src++;
	return (orig);
}
