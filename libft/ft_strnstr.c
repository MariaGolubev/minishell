/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/08 13:38:13 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/10/15 10:56:39 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *sub, size_t n)
{
	size_t	sub_len;

	sub_len = ft_strlen(sub);
	if (sub_len == 0)
		return ((char *)src);
	if (n == 0)
		return (NULL);
	while (*src && n >= sub_len)
	{
		if (ft_strncmp(src, sub, sub_len) == 0)
			return ((char *)src);
		src++;
		n--;
	}
	return (NULL);
}
