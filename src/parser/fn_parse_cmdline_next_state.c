/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fn_parse_cmdline_next_state.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgolubev <mgolubev@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/12/05 17:47:58 by mgolubev      #+#    #+#                 */
/*   Updated: 2024/12/07 16:02:28 by mgolubev      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	fn_is_envkey(char *key)
{
	if (!key || ft_isdigit(*key))
		return (0);
	while (*key && (ft_isalnum(*key) || *key == '_'))
		key++;
	return (*key == '\0');
}

static int	fn_is_setenv(t_token *token)
{
	return (token && token->type == TOKEN_WORD
		&& token->next && token->next->type == TOKEN_ASSIGN
		&& fn_is_envkey(token->value));
}

static int	fn_is_redirect(t_token *token)
{
	return (token && (token->type == TOKEN_REDIRECT_IN
			|| token->type == TOKEN_REDIRECT_OUT
			|| token->type == TOKEN_APPEND_OUT));
}

static int	fn_is_heredoc(t_token *token)
{
	return (token && token->type == TOKEN_HEREDOC_START);
}

t_cmdline_state	fn_parse_cmdline_next_state(t_cmdline *data, t_token **token)
{
	while (*token && (*token)->type == TOKEN_SPACE)
		*token = (*token)->next;
	if (fn_is_setenv(*token))
	{
		if (data->cmd == NULL)
			return (CMDLINE_SETENV);
		return (CMDLINE_ARG);
	}
	else if (fn_is_redirect(*token))
		return (CMDLINE_REDIRECT);
	else if (fn_is_heredoc(*token))
		return (CMDLINE_HEREDOC);
	else if (fn_is_simple_token(*token))
	{
		if (data->cmd == NULL)
			return (CMDLINE_CMD);
		return (CMDLINE_ARG);
	}
	else
		return (CMDLINE_DONE);
}
