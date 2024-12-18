/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/09 11:24:35 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/10/14 16:30:27 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <assert.h>

void	ft_striteri(char *str, void (*fn)(unsigned int, char *))
{
	size_t	pos;

	pos = 0;
	while (str[pos] != '\0')
	{
		fn((unsigned int)pos, &str[pos]);
		pos++;
	}
}

#ifdef TEST

void	f_toupper(unsigned int i, char *ch)
{
	(void)i;
	if ((unsigned )*ch - 'a' < 26)
		*ch = *ch - 32;
}

int	main(void)
{
	char	*from;
	char	*to;
	char	*buff;

	from = "Hello my world";
	to = "HELLO MY WORLD";
	buff = ft_strdup(from);
	if (buff == NULL)
		return (-1);
	ft_striteri(buff, f_toupper);
	ft_putendl_fd(buff, 1);
	assert(!ft_memcmp(buff, to, ft_strlen(from)));
	free(buff);
}
#endif
