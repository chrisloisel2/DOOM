/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collomn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 13:39:34 by lchristo          #+#    #+#             */
/*   Updated: 2020/08/20 14:54:33 by lchristo         ###   ########.fr       */
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

void	ft_putpixel(t_t *t, float hauteur, int i, float index)
{
	float p;
	float n;
	int y;

	n = (float)t->noh / (float)hauteur;
	y = (index * n);
	p = (float)((ft_get_h(t, i)) * t->nol) + ((float)t->nol * (float)y);
	t->si[i] = t->strno[(int)p];
}

void	ft_reducto(t_t *t, float hauteur, int i)
{
	float	index;
	int		max;
	int		min;

	index = 0;
	if (hauteur > t->speed[i])
		max = hauteur;
	else
		max = t->speed[i];
	min = (t->milieu - (t->win_x * (max / 2)));
	max = (t->milieu + (t->win_x * (max / 2)));
	i = i + min;
	while (i < max)
	{
		if (i < t->milieub)
			t->si[i] = t->ccolor;
		else if (i > t->milieuh)
			t->si[i] = t->fcolor;
		else
			ft_putpixel(t, hauteur, i, index++);
		i += t->win_x;
	}
}

void	ft_collomn(t_t *t, int i)
{
	float	dist;
	float	hauteur;
	float	index;

	index = 0;
	dist = pow(t->distx, 2) + pow(t->disty, 2);
	hauteur = (t->cam_distance * t->mur_h) / dist;
	t->milieu = (t->win_x * (t->win_y / 2));
	t->milieuh = (t->milieu + (t->win_x * (hauteur / 2)));
	t->milieub = (t->milieu - (t->win_x * (hauteur / 2)));
	if (t->speed[i] != 0)
		ft_reducto(t, hauteur, i);
	else
	{
		while (i < (t->win_x * t->win_y))
		{
			if (i > t->milieuh)
				t->si[i] = t->fcolor;
			else if (i < t->milieub)
				t->si[i] = t->ccolor;
			else
				ft_putpixel(t,  hauteur, i, index++);
			i += t->win_x;
		}
		t->speed[i] = hauteur;
		mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->image, 0, 0);
	}
}
