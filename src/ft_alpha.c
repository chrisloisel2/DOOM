/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alpha.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 01:14:15 by lchristo          #+#    #+#             */
/*   Updated: 2021/01/05 20:40:17 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

int		ft_alpha(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_white_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f' ||
			c == '\r')
		return (1);
	return (0);
}

int		ft_get_player_two(char c, t_t *t)
{
	if (c == 'S')
	{
		t->planex = -0.66;
		t->planey = 0.0;
		t->diry = 1.0;
		t->dirx = 0.0;
		return (1);
	}
	if (c == 'W')
	{
		t->planex = 0.0;
		t->planey = -0.66;
		t->diry = 0.0;
		t->dirx = -1.0;
		return (1);
	}
	return (0);
}
