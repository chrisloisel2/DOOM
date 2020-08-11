/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collomn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 13:39:34 by lchristo          #+#    #+#             */
/*   Updated: 2020/08/11 18:47:41 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	ft_collomn(t_t *t, int i)
{
	float	dist;
	float	distx;
	float	disty;
	int		hauteur;
	int		h;
	int		milieu;

	h = t->win_y;
	distx = t->x - t->murx;
	disty = t->y - t->mury;
	dist = pow(distx, 2) + pow(disty, 2);	
	hauteur = (t->cam_distance * t->win_y / 10) / dist;
	if (t->rot > t->minray)
		hauteur = hauteur * cos(t->rot - t->minray);
	else
		hauteur = hauteur * cos(t->minray - t->rot);
	printf("ray =%f, rot =%f, hauteur = %d\n", t->minray, t->rot, hauteur);
	milieu = (t->win_x * (t->win_y / 2));
	while (i < (t->win_x * t->win_y))
	{
		if (i < (milieu - (t->win_x * (hauteur / 2))))
			t->si[i] = t->ccolor;
		else if (i > (milieu + (t->win_x * (hauteur / 2))))
			t->si[i] = t->fcolor;
		else
			t->si[i] = 0xff00ff;
		i += t->win_x;
	}
	mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->image, 0, 0);
}
