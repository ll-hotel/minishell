/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 15:38:30 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/05/26 05:09:55 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_operator(int c)
{
	return (c == '$' \
			|| c == '\'' || c == '\"' \
			|| c == '|' || c == '<' || c == '>');
}
