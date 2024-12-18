/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/08 10:08:33 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/10/11 13:54:14 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	while (*src && *src != ch)
		src++;
	if (*src == ch)
		return ((char *)src);
	return (NULL);
}
