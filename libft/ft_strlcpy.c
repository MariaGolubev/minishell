/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/08 12:41:48 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/10/11 13:54:32 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	srcsize;

	srcsize = ft_strlen(src);
	if (!destsize)
		return (srcsize);
	while (*src && destsize > 1)
	{
		*dest = *src;
		dest++;
		src++;
		destsize--;
	}
	*dest = '\0';
	return (srcsize);
}
