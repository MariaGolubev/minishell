/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin_with.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: selcyilm <selcyilm@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/10 14:56:35 by selcyilm      #+#    #+#                 */
/*   Updated: 2024/12/10 15:01:12 by selcyilm      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_with(char *s1, char *s2, char c)
{
	char	*dest;
	size_t	str1_len;
	size_t	str2_len;
	char	tmp[2];

	tmp[0] = c;
	tmp[1] = '\0';
	str1_len = ft_strlen(s1);
	str2_len = ft_strlen(s2);
	dest = (char *)malloc(sizeof(char) * (str1_len + str2_len + 2));
	if (dest == NULL)
		return (NULL);
	ft_strlcat(dest, s1, str1_len + str2_len + 2);
	ft_strlcat(dest, tmp, str1_len + str2_len + 2);
	ft_strlcat(dest + str1_len, s2, str1_len + str2_len + 2);
	return (dest);
}
