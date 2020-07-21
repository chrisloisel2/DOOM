/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 04:57:07 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/21 04:18:15 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"



void		ft_check_wall(t_t *t)
{
	int 	y;
	int 	x;
	float	ray;

	ray = 0;
	y = t->y;
	x = t->x;
	t->rot = 20;
	printf("[%d][%d] ->[%f][%f] %c\n", y, x, t->yray, t->xray, t->tb[y][x]);
	while (y < t->maxy && x < t->maxx && t->tb[y][x] != '1')
	{
		ray = ray + 0.01;
		t->yray = (ray * cos(t->rot));
		t->xray = (ray * cos(90 - t->rot));
		y = y + (int) t->yray;
		x = x + (int) t->xray;
	}
	printf("[%d][%d] ->[%f][%f] %c\n", y, x, t->yray, t->xray, t->tb[y][x]);
}

void		ft_screen(t_t *t)
{
	t->yray = 0;
	t->xray = 0;
	ft_check_wall(t);
}
