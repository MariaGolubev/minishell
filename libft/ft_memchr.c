/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/08 10:08:03 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/10/11 13:53:36 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	const unsigned char	*s;
	unsigned char		ch;

	s = (const unsigned char *)src;
	ch = (unsigned char)c;
	while (n)
	{
		if (*s == ch)
			return ((void *)s);
		s++;
		n--;
	}
	return (NULL);
}
