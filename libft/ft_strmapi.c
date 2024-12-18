/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                        :+:    :+:           */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/09 11:07:17 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/10/29 16:36:43 by mgolubev       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *str, char (*fn)(unsigned int, char))
{
	size_t			len;
	char			*mstr;
	unsigned int	pos;

	len = ft_strlen(str);
	mstr = malloc((len + 1) * sizeof(char));
	if (mstr == NULL)
		return (NULL);
	mstr[len] = '\0';
	pos = 0;
	while (str[pos])
	{
		mstr[pos] = fn(pos, str[pos]);
		pos++;
	}
	return (mstr);
}
