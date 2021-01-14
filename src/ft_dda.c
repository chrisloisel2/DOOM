/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 04:57:07 by lchristo          #+#    #+#             */
/*   Updated: 2021/01/13 17:18:18 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void		ft_setupdda(t_t *t, int x)
{
	t->camerax = ((x / (double)t->win_x) * 2) - 1;
	t->raydirx = t->dirx + (t->planex * t->camerax);
	t->raydiry = t->diry + (t->planey * t->camerax);
	t->casey = (int)t->y;
	t->casex = (int)t->x;
	t->deltadistx = sqrt(1 + (t->raydiry * t->raydiry) / (t->raydirx * t->raydirx));
	t->deltadisty = sqrt(1 + (t->raydirx * t->raydirx) / (t->raydiry * t->raydiry));
	t->side = 0;
	if (t->raydirx < 0)
	{
		t->stepx = -1;
		t->sidedistx = (t->x - t->casex) * t->deltadistx;
	}
	else
	{
		t->stepx = 1;
		t->sidedistx = (t->casex + 1.0 - t->x) * t->deltadistx;
	}
	if (t->raydiry < 0)
	{
		t->stepy = -1;
		t->sidedisty = (t->y - t->casey) * t->deltadisty;
	}
	else
	{
		t->stepy = 1;
		t->sidedisty = (t->casey + 1.0 - t->y) * t->deltadisty;
	}
}

void		ft_cheapdda(t_t *t, float lineheight)
{
	int hit ;

	hit = 0;
	while (hit == 0)
	{
		if (t->sidedistx < t->sidedisty)
		{
			t->sidedistx += t->deltadistx;
			t->casex += t->stepx;
			t->side = 0;
		}
		else
		{
			t->sidedisty += t->deltadisty;
			t->casey += t->stepy;
			t->side = 1;
		}
		if (t->tb[t->casey][t->casex] == '1')
			hit = 1;
	}
	if (t->side == 0)
		t->perpwalldist = (t->casex - t->x + (1 - t->stepx) / 2) / t->raydirx;
	else
		t->perpwalldist = (t->casey - t->y + (1 - t->stepy) / 2) / t->raydiry;
	lineheight = (t->win_y / t->perpwalldist);
	t->drawStart = -lineheight / 2 + t->win_y / 2;
	if (t->drawStart < 0)
		t->drawStart = 0;
	t->drawEnd = lineheight / 2 + t->win_y / 2;
	if (t->drawEnd >= t->win_y)
		t->drawEnd = t->win_y - 1;
}
