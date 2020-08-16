/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collomn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 13:39:34 by lchristo          #+#    #+#             */
/*   Updated: 2020/08/16 18:53:55 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

int		ft_putpixel(t_t *t, int i)
{
	int y;
	int x;

	y = (t->mury - (int)t->mury) * 100;
	x = (t->murx - (int)t->murx) * 100;
	if (x > y)
		return (x);
	return (y);
}

void	ft_collomn(t_t *t, int i)
{
	float	dist;
	float	hauteur;
	int		h;
	int		milieu;

	if (t->rot > t->minray)
		h = (t->rot - t->minray);
	else
		h = (t->minray - t->rot);
	t->distx = t->x - t->murx;
	t->distx *= cos(h);
	t->disty = t->y - t->mury;
	t->disty *= cos(h);
	dist = pow(t->distx, 2) + pow(t->disty, 2);	
	hauteur = (t->cam_distance * t->mur_h) / dist;
	milieu = (t->win_x * (t->win_y / 2));
	h = ft_putpixel(t, i);
	while (i < (t->win_x * t->win_y))
	{
		if (i < (milieu - (t->win_x * (hauteur / 2))))
			t->si[i] = t->ccolor;
		else if (i > (milieu + (t->win_x * (hauteur / 2))))
			t->si[i] = t->fcolor;
		else
		{
			t->si[i] = t->csno[h];
			h += 100;
		}
		i += t->win_x;
	}
	mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->image, 0, 0);
}
