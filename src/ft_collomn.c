/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collomn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 13:39:34 by lchristo          #+#    #+#             */
/*   Updated: 2020/08/15 18:28:50 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	ft_collomn(t_t *t, int i)
{
	float	dist;
	float	distx;
	float	disty;
	float	hauteur;
	float	h;
	int		milieu;

	t->mur_h = 100;
	if (t->rot > t->minray)
		h = (t->rot - t->minray);
	else
		h = (t->minray - t->rot);
	distx = t->x - t->murx;
	distx *= cos(h);
	disty = t->y - t->mury;
	disty *= cos(h);
	dist = pow(distx, 2) + pow(disty, 2);	
	hauteur = (t->cam_distance * t->mur_h) / dist;
	milieu = (t->win_x * (t->win_y / 2));
	while (i < (t->win_x * t->win_y))
	{
		if (i < (milieu - (t->win_x * (hauteur / 2))))
			t->si[i] = t->ccolor;
		else if (i > (milieu + (t->win_x * (hauteur / 2))))
			t->si[i] = t->fcolor;
		else
			t->si[i] = t->csno[5];
		i += t->win_x;
	}
	mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->image, 0, 0);
}
