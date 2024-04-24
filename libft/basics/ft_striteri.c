/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ll-hotel <ll-hotel@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 20:43:28 by ll-hotel          #+#    #+#             */
/*   Updated: 2024/02/23 03:43:47 by ll-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned long long	i;

	if (!s)
		return ;
	i = -1;
	while (s[++i])
		(*f)(i, s + i);
	s[i] = 0;
}
