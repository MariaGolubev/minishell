/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                          :+:    :+:           */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/08 18:16:33 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/10/29 16:33:10 by mgolubev       ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**f_new_array(size_t count)
{
	char	**arr;
	size_t	i;

	arr = (char **)malloc((count + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < count + 1)
		arr[i++] = NULL;
	return (arr);
}

static char	**f_free_array(char **arr)
{
	size_t	i;

	if (arr == NULL)
		return (NULL);
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	*f_next_substring(const char **src, char c)
{
	const char	*start;
	size_t		len;
	char		*substring;

	start = NULL;
	len = 0;
	while (**src && **src == c)
		(*src)++;
	start = *src;
	while (**src && **src != c)
	{
		len++;
		(*src)++;
	}
	substring = (char *)malloc((len + 1) * sizeof(char));
	if (substring == NULL)
		return (NULL);
	substring[len] = '\0';
	return (ft_memcpy(substring, start, len));
}

static size_t	f_count_substring(const char *src, char c)
{
	size_t	count;

	count = 0;
	while (*src && *src == c)
		src++;
	while (*src)
	{
		if (*src != c)
		{
			count++;
			while (*src && *src != c)
				src++;
		}
		else
			src++;
	}
	return (count);
}

char	**ft_split(const char *src, char c)
{
	size_t	count;
	size_t	i;
	char	**arr;

	count = f_count_substring(src, c);
	if (count == 0)
		return (f_new_array(0));
	arr = f_new_array(count);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		arr[i] = f_next_substring(&src, c);
		if (arr[i] == NULL)
			return (f_free_array(arr));
		i++;
	}
	return (arr);
}
