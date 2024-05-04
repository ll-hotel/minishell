/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_on_cuts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 23:04:25 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/05/04 16:24:04 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*lexer_on_cut(t_llst_head *token_lst, char *cut);

t_token	*lexer_on_cuts(char **cuts)
{
	t_llst_head	token_lst;
	void		*space;

	if (!cuts)
		return (NULL);
	token_lst.first = NULL;
	while (*cuts)
	{
		if (!lexer_on_cut(&token_lst, *(cuts++)))
		{
			llst_clear(&token_lst, &token_delete);
			return (NULL);
		}
		if (!*cuts)
			break ;
		space = token_new(NULL, TOKEN_SPACE);
		if (!space)
		{
			llst_clear(&token_lst, &token_delete);
			return (NULL);
		}
		llst_addback(&token_lst, space);
	}
	return ((t_token *)token_lst.first);
}

static t_token	*lexer_on_cut(t_llst_head *token_lst, char *cut)
{
	t_token	*token;
	char	simple_quoted;
	int		i;

	simple_quoted = 0;
	i = 0;
	while (cut[i])
	{
		token = NULL;
		if (is_operator(cut[i]))
		{
			if (cut[i] == '\'')
				simple_quoted = !simple_quoted;
			token = lexer_operator(cut, &i);
		}
		else
			token = lexer_word(cut, &i, simple_quoted);
		if (!token)
			return (NULL);
		llst_addback(token_lst, (t_llst *)token);
	}
	return (token);
}
