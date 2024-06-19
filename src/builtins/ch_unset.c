/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 06:53:03 by lrichaud          #+#    #+#             */
/*   Updated: 2024/06/17 22:04:13 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniChell.h"

int	ch_unset(t_cmd *cmd, t_ch *ch)
{
	t_evar		*vars;
	t_llst_head	*previous_vars;

	previous_vars = &ch->evars;
	if (cmd->argc < 2)
		return (0);
	vars = (t_evar *)ch->evars.first;
	while (vars && ft_strncmp(vars->name, cmd->argv[1], \
		ft_strlen(cmd->argv[1])))
	{
		previous_vars = (t_llst_head *) previous_vars->first;
		vars = vars->next;
	}
	if (vars)
		llst_delone((void *) previous_vars, evar_free);
	return (0);
}