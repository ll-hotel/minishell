/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_dquote.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 05:09:01 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/05/28 15:22:03 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*sub_word(char *line, int *p_i);

t_token	*lexer_dquote(char *line, int *p_i)
{
	t_token		*dq_token;
	t_token		*w;
	int			i;

	if (!ft_strchr(line + 1, '\"'))
		return (msh_syntax_err(-'\"'), NULL);
	dq_token = token_new(NULL, TOKEN_DQUOTE);
	if (!dq_token)
		return (NULL);
	dq_token->inner_tokens.first = \
			(t_llst *)token_new(ft_calloc(1, 1), TOKEN_WORD);
	if (!dq_token->inner_tokens.first || \
			!((t_token *)dq_token->inner_tokens.first)->str)
		return (ft_free(dq_token));
	i = 1;
	while (line[i] && line[i] != '\"')
	{
		if (line[i] == '$')
			w = lexer_dollar(line + i, p_i);
		else
			w = sub_word(line + i, p_i);
		i += *p_i;
		if (!w)
			return (token_free(dq_token), NULL);
		llst_addback(&dq_token->inner_tokens, (t_llst *)w);
	}
	*p_i = i + 1;
	return (dq_token);
}

static t_token	*sub_word(char *line, int *p_i)
{
	int		i;
	char	*s;

	i = 0;
	while (line[i] && line[i] != '\"' && line[i] != '$')
		i += 1;
	*p_i = i;
	s = ft_substr(line, 0, i);
	if (s)
		return (token_new(s, TOKEN_WORD));
	return (NULL);
}
