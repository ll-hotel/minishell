/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrichaud <lrichaud@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 06:51:48 by lrichaud          #+#    #+#             */
/*   Updated: 2024/06/03 11:32:53 by lrichaud         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	env_var_is_valid(char *arg);

int	msh_export(t_command *cmd, t_msh *msh)
{
	t_env_var	*new_env_var;
	t_env_var	*vars;

	if (ft_strchr(cmd->argv[1], '='))
	{
		new_env_var = env_var_new(cmd->argv[1]);
		if (!new_env_var)
			return (1);
		vars = (t_env_var *)msh->env_vars.first;
		while (vars && ft_strncmp(vars->name, new_env_var->name, \
			ft_strlen(new_env_var->name)))
			vars = vars->next;
		if (!env_var_is_valid(new_env_var->name))
			return (1);
		if (!vars)
			llst_addback(&msh->env_vars, (t_llst *)new_env_var);
		else if (new_env_var->value)
		{
			ft_free(vars->value);
			vars->value = ft_strdup(new_env_var->value);
			if (!vars->value)
				return (perror("minishell"), 1);
		}
	}
	return (0);
}

static int	env_var_is_valid(char *arg)
{
	size_t	i;

	i = 1;
	if (!ft_isalpha(arg[0]))
		return (0);
	while (ft_isalnum(arg[i]))
		i++;
	if (arg[i])
	{
		write(2, "export : not a valid identifier\n", 32);
		return (0);
	}
	return (1);
}
