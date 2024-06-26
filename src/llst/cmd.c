/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:59:00 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/06/17 21:51:04 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minichell.h"

void	cmd_free(void *_cmd)
{
	t_cmd *const	cmd = _cmd;

	if (cmd)
	{
		cmd->fd_in = ft_close(cmd->fd_in);
		cmd->fd_out = ft_close(cmd->fd_out);
		ft_free(cmd->executable);
		llst_clear(&cmd->redirs, token_free);
		ft_free_parray(cmd->argv);
		ft_free_parray(cmd->envp);
		if (cmd->path)
			ft_free(cmd->path[0]);
		ft_free(cmd->path);
		ft_bzero(cmd, sizeof(*cmd));
		free(cmd);
	}
}
