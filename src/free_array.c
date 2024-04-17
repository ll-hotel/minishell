/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 23:54:21 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/04/27 18:15:43 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_array(void **ptr)
{
	void *const	p = ptr;

	if (ptr)
	{
		while (*ptr)
			free(*(ptr++));
		free(p);
	}
}
