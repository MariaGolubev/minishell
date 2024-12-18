/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/08 14:35:30 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/10/11 13:54:17 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*buf;
	size_t	size;

	size = ft_strlen(str) + 1;
	buf = (char *)malloc(size);
	if (buf == NULL)
		return (NULL);
	return ((char *)ft_memcpy(buf, str, size));
}
