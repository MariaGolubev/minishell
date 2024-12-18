/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_lexer_comment.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: maria <maria@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/28 20:19:06 by maria         #+#    #+#                 */
/*   Updated: 2024/12/09 11:48:50 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer_state_type	fn_lexer_comment(const char **input, t_token **tokens)
{
	char	*buffer;
	int		index;
	t_token	*token;

	index = 0;
	(*input)++;
	if (ft_strchr(*input, '\n'))
		buffer = (char *)malloc((ft_strchr(*input, '\n') - *input + 1)
				* sizeof(char));
	else
		buffer = (char *)malloc((ft_strlen(*input) + 1) * sizeof(char));
	while (**input && **input != '\n' && index < BUFFER_SIZE - 1)
	{
		buffer[index++] = **input;
		(*input)++;
	}
	buffer[index] = '\0';
	token = fn_token_new(TOKEN_COMMENT, buffer);
	free(buffer);
	if (token == NULL)
		return (LEXER_ERR);
	fn_token_add(tokens, token);
	return (fn_lexer_next_state(*input));
}
