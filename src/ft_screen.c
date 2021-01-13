/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 04:57:07 by lchristo          #+#    #+#             */
/*   Updated: 2021/01/05 19:42:00 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void		ft_screen(t_t *t)
{
	float			angle;
	float			min;
	float			max;
	int				x;
	int				stepx;
	int				stepy;
	double			raydirx;
	double			raydiry;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	double			sidedistx;
	double			sidedisty;
	double			camerax;
	double			time;
	double			oldtime;
	int				de;
	int				hit;
	int				p;
	double			wallx;
	int				texx;
	int				y;
	double			lineheight;
	unsigned int	color;

	x = 0;
	angle = 40.0 / t->win_x;
	while (x < t->win_x)
	{
		camerax = ((x / (double)t->win_x) * 2) - 1;
		raydirx = t->dirx + (t->planex * camerax);
		raydiry = t->diry + (t->planey * camerax);
		t->casey = (int)t->y;
		t->casex = (int)t->x;
		deltadistx = sqrt(1 + (raydiry * raydiry) / (raydirx * raydirx));
		deltadisty = sqrt(1 + (raydirx * raydirx) / (raydiry * raydiry));
		t->side = 0;
		hit = 0;
		if (raydirx < 0)
		{
			stepx = -1;
			sidedistx = (t->x - t->casex) * deltadistx;
		}
		else
		{
			stepx = 1;
			sidedistx = (t->casex + 1.0 - t->x) * deltadistx;
		}
		if (raydiry < 0)
		{
			stepy = -1;
			sidedisty = (t->y - t->casey) * deltadisty;
		}
		else
		{
			stepy = 1;
			sidedisty = (t->casey + 1.0 - t->y) * deltadisty;
		}
		while (hit == 0)
		{
			if (sidedistx < sidedisty)
			{
				sidedistx += deltadistx;
				t->casex += stepx;
				t->side = 0;
			}
			else
			{
				sidedisty += deltadisty;
				t->casey += stepy;
				t->side = 1;
			}
			if (t->tb[t->casey][t->casex] == '1')
				hit = 1;
		}
		if (t->side == 0)
			perpwalldist = (t->casex - t->x + (1 - stepx) / 2) / raydirx;
		else
			perpwalldist = (t->casey - t->y + (1 - stepy) / 2) / raydiry;
		lineheight = (t->win_y / perpwalldist);
		t->drawStart = -lineheight / 2 + t->win_y / 2;
		if (t->drawStart < 0)
			t->drawStart = 0;
		t->drawEnd = lineheight / 2 + t->win_y / 2;
		if (t->drawEnd >= t->win_y)
			t->drawEnd = t->win_y - 1;
		y = x;
		if (t->side == 0)
			wallx = t->y + perpwalldist * raydiry;
		else
			wallx = t->x + perpwalldist * raydirx;
		de = 0;
		int	ix = (wallx - (int)wallx) * t->th[0];
		while (y < (t->win_x * t->win_y))
		{
			float yolo = 0;
			float index = 0;
			float res;				
			if (y > (t->drawEnd * t->win_x))
				t->si[y] = t->fcolor;
			if (y < (t->drawStart * t->win_x))
				t->si[y] = t->ccolor;
			while (y >= (t->drawStart * t->win_x) && y <= (t->drawEnd * t->win_x))
			{
				float hauteur;
				hauteur = (t->drawEnd - t->drawStart);
				yolo = (index / hauteur);
				res = (yolo + ix) * t->th[0];
				color = t->tx[0][(int)(res)];
//				if (t->side == 1)
//					color = (color> 1) & 8355711;
				t->si[y] = color;
				y += t->win_x;
				index++;
			}
			y += t->win_x;
		}
		x++;
	}
	mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->image, 0, 0);
}
