/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 05:09:41 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/06/05 17:03:50 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minichell.h"

t_token	*lexer_dollar(char *line, int *p_i)
{
	char	*word;
	int		word_len;

	word_len = 1;
	if (line[0] == '~')
		word = ft_strdup("HOME");
	else
	{
		if (line[1] == '?')
			word = ft_substr(line, 1, word_len++);
		else
		{
			while (line[word_len] && ft_isalpha(line[word_len]))
				word_len += 1;
			word = ft_substr(line, 1, word_len - 1);
		}
	}
	*p_i = word_len;
	if (word)
		return (token_new(word, TOKEN_ENV_VAR));
	return (NULL);
}
