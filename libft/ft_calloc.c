/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/08 14:25:38 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/10/14 18:36:20 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t m, size_t n)
{
	void	*buff;

	if (n && m > __SIZE_MAX__ / n)
		return (NULL);
	n = n * m;
	buff = malloc(n);
	if (buff == NULL)
		return (NULL);
	ft_bzero(buff, n);
	return (buff);
}
