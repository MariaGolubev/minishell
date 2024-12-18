/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                        :+:    :+:           */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/08 16:00:29 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/10/29 16:41:56 by mgolubev       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*dest;
	size_t	str1_len;
	size_t	str2_len;

	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	dest = (char *)malloc((str1_len + str2_len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, str1, str1_len);
	ft_memcpy(dest + str1_len, str2, str2_len);
	dest[str1_len + str2_len] = '\0';
	return (dest);
}
