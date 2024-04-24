/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 20:52:27 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/04/24 17:58:43 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "basics.h"
#include <stdlib.h>

void	*ft_realloc(void *p, unsigned long old_size, unsigned long n)
{
	void	*new;

	if (n == 0)
		return (NULL);
	new = malloc(n);
	if (!new)
		return (NULL);
	if (!p)
		return (new);
	if (n < old_size)
		ft_memmove(new, p, n);
	else
		(void)ft_memmove(new, p, old_size);
	return (free(p), new);
}
