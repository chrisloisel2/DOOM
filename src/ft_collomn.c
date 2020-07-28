/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collomn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 13:39:34 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/28 18:20:54 by lchristo         ###   ########.fr       */
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
	while (h > hauteur)
	{
		mlx_pixel_put(t->mlx_ptr, t->mlx_win, i, h, t->fcolor);
		h--;
	}
	h = 0;
	while (h < t->win_y / 2)
	{
		mlx_pixel_put(t->mlx_ptr, t->mlx_win, i, h, t->ccolor);
		h++;
	}
	while (hauteur > 0)
	{
		mlx_pixel_put(t->mlx_ptr, t->mlx_win, i, (int)((t->win_y / 2) - hauteur), 0xff0000);
		hauteur--;
	}
}
