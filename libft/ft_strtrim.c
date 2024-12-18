/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                        :+:    :+:           */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/08 16:47:33 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/10/29 16:21:37 by mgolubev       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	f_start(const char *src, const char *set)
{
	size_t	start;

	start = 0;
	while (src[start] && ft_strchr(set, src[start]))
		start++;
	return (start);
}

static size_t	f_end(size_t start, const char *src, const char *set)
{
	size_t	end;

	end = start;
	while (src[end])
		end++;
	while (end > start && ft_strchr(set, src[end - 1]))
		end--;
	return (end);
}

char	*ft_strtrim(const char *src, const char *set)
{
	size_t	start;
	size_t	end;
	char	*buff;

	start = f_start(src, set);
	end = f_end(start, src, set);
	buff = malloc((end - start + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	buff[end - start] = '\0';
	return (ft_memcpy(buff, &src[start], end - start));
}
