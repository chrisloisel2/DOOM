/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collomn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 13:39:34 by lchristo          #+#    #+#             */
/*   Updated: 2020/08/06 18:41:35 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	ft_collomn(t_t *t, int i)
{
	float	dist;
	float	distx;
	float	disty;
	float	hauteur;
	int		h;
	int		milieu;

	h = t->win_y;
	distx = t->x - t->murx;
	disty = t->y - t->mury;
	dist = pow(distx, 2) + pow(disty, 2);	
	hauteur = (t->cam_distance * t->win_y / 2) / dist;
//	if ((t->minray > M_PI / 2))
//		hauteur = hauteur * tan(M_PI - t->minray);
//	else
//		hauteur = hauteur * cos(t->minray);
	milieu = (t->win_x * (t->win_y / 2));
	while (i < (t->win_x * t->win_y))
	{
		if (i < (milieu - (t->win_x * (hauteur / 2))))
			t->si[i] = t->ccolor;
		else if (i > (milieu + (t->win_x * (hauteur / 2))))
			t->si[i] = t->fcolor;
		else
			t->si[i] = 0xff0000;
		i += t->win_x;
	}
	mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->image, 0, 0);
}
