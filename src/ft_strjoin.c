/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 04:28:24 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/07 02:19:39 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	ft_free_strjoin(char *s1, char *s2, char **leaks)
{
	char *new;

	new = *leaks;
	*leaks = ft_strjoin(s1, s2);
	(new) ? free(new) : 0;
	new = NULL;
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		y;

	if (!(s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	y = 0;
	while (s1[i] != '\0')
	{
		s[y] = s1[i];
		i++;
		y++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		s[y] = s2[i];
		y++;
		i++;
	}
	s[y] = '\0';
	return (s);
}
