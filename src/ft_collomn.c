/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collomn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 13:39:34 by lchristo          #+#    #+#             */
/*   Updated: 2020/08/19 16:32:13 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

float		ft_get_h(t_t *t, int i)
{
	float y;
	float x;

	y = 0;
	x = 0;
	y = (t->mury - (int)t->mury);
	x = (t->murx - (int)t->murx);
	if (x > y)
		return (x);
	return (y);
}

int		ft_putpixel(t_t *t, float hauteur, int i)
{
	float h;
	float index;
	float p;
	float n;
	int y;

	index = 0;
	y = 0;
	n = (float)t->textureh / (float)hauteur;
	while (index < hauteur && i < (t->win_x * t->win_y))
	{
		y = (index * n);
		p = (float)((ft_get_h(t, i)) * t->texturel) + ((float)t->texturel * (float)y);
		t->si[i] = t->csno[(int)p];
		index++;
		i += t->win_x;
	}
	return (i);
}

void	ft_collomn(t_t *t, int i)
{
	float	dist;
	float	hauteur;
	int		milieu;

	dist = pow(t->distx, 2) + pow(t->disty, 2);
	hauteur = (t->cam_distance * t->mur_h) / dist;
	milieu = (t->win_x * (t->win_y / 2));
	while (i < (t->win_x * t->win_y))
	{
		if (i < (milieu - (t->win_x * (hauteur / 2))))
			t->si[i] = t->ccolor;
		else if (i > (milieu + (t->win_x * (hauteur / 2))))
			t->si[i] = t->fcolor;
		else
			i = ft_putpixel(t, hauteur, i);
		i += t->win_x;
	}
	mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->image, 0, 0);
}
