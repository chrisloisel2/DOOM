/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 04:57:07 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/22 06:21:21 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"



void		ft_check_wall(t_t *t)
{
	float 	y;
	float 	ya;
	float 	x;
	float 	x1;
	float 	x2;
	float	ray;
	float	tempo;

	ya = 1;
	ray = 0;
	x1 = 0;
	x2 = 0;
	y = t->y + 0.5;
	x = t->x + 0.5;
	printf("rot = %f\n", t->rot);
	t->rot = t->rot * (M_PI/180);
	ya = (y - (int)y);
	if (t->rot < 0)
		ya = -ya;
	printf("rot = %f  ya = %f (%f - %d)\n", t->rot, ya, y, (int)y);
	x1 = ya / tan(t->rot);
	printf("rot = %f  x1= %f  (%f / %f)\n", t->rot, x1, ya, tan(t->rot));
}

void		ft_screen(t_t *t)
{
	int i;

	i = 0;
	t->yray = 0;
	t->xray = 0;
	ft_check_wall(t);
	i = 0;
	while (i < t->maxy)
	{
		printf("->%s\n", t->tb[i]);
		i++;
	}
}
