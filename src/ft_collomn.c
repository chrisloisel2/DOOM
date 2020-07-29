/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collomn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 13:39:34 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/29 15:09:33 by lchristo         ###   ########.fr       */
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

	h = t->win_y;
	distx = t->x - t->murx;
	disty = t->y - t->mury;
	dist = pow(distx, 2) + pow(disty, 2);	
	hauteur = (t->cam_distance * 300) / dist;
	while (i < t->win_x * ((t->win_y / 2) - (hauteur / 2)))
	{
		t->si[i] = t->fcolor;
		i += t->win_x;
	}
	while (hauteur > 0)
	{
		t->si[i] = 0xff0096;
		hauteur--;
		i += t->win_x;
	}
	while (i < (t->win_x * t->win_y))
	{
		t->si[i] = t->ccolor;
		i += t->win_x;
	}
	mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->image, 0, 0);
}
