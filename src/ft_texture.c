/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 01:14:15 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/07 02:25:13 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

int		ft_side(t_t *t)
{
	if (t->side == 0)
	{
		if (t->raydirx > 0)
			return (2);
		else
			return (1);
	}
	if (t->side == 1)
	{
		if (t->raydiry > 0)
			return (3); //sud
		else
			return (0); // nord
	}
	return (1);
}

void	ft_diff_texture(t_t *t, int y, int index, int x)
{
	float			res;
	float			hauteur;
	int				ygrek;
	unsigned int	color;
	int 			tex;

	tex = ft_side(t);
	hauteur = (t->drawEnd - t->drawStart);
	ygrek = (index / hauteur) * t->th[tex];
	res = ygrek * t->tl[tex] + x;
	if (res < t->tl[tex] * t->th[tex])
		color = t->tx[tex][(int)(res)];
	(t->side == 1) ? color = (color >> 1) & 8355711 : 0;
	t->si[y] = color;
}

void	ft_pixel_texture(t_t *t, int y)
{
	double			wallx;
	float			index;
	int				x;

	index = 0;
	if (t->side == 0)
		wallx = t->y + t->perpwalldist * t->raydiry;
	else
		wallx = t->x + t->perpwalldist * t->raydirx;
	while (y < (t->win_x * t->win_y))
	{			
		(y > (t->drawEnd * t->win_x)) ? t->si[y] = t->fcolor : 0;
		(y < (t->drawStart * t->win_x)) ? t->si[y] = t->ccolor : 0;
		while (y >= (t->drawStart * t->win_x) && y <= (t->drawEnd * t->win_x))
		{
			x = (wallx - (int)wallx) * t->tl[ft_side(t)];
			ft_diff_texture(t, y, index, x);
			index++;
			y += t->win_x;
		}
		y += t->win_x;
	}
}
