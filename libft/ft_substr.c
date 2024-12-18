/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                         :+:    :+:           */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/08 15:28:31 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/10/29 16:43:18 by mgolubev       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *src, unsigned int start, size_t len)
{
	size_t	src_len;
	char	*substr;

	substr = NULL;
	src_len = ft_strlen(src);
	if (start >= src_len)
		return (ft_calloc(1, sizeof(char)));
	if (start + len > src_len)
		len = src_len - start;
	substr = malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	substr[len] = '\0';
	return (ft_memcpy(substr, &src[start], len));
}
