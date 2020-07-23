/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 04:57:07 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/23 12:23:18 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void		ft_check_horizontal_wall(t_t *t)
{
	float 	ya;
	float	yb;
	float 	x1;
	float 	x2;
	double	i;

	printf("horizontal\n");
	ya = (t->x - (int)t->x);
	x1 = 0;
	x2 = 0;
	i = tan(t->rot);
//	printf("x1 =%f ya(%f)/i(%f)\n", x1, ya, i);
	if (t->rot == (float)M_PI || t->rot == (float)(0))
		i = 1;
	x1 = ya / i;
//	printf("x1 =%f ya(%f)/i(%f)\n", x1, ya, i);
	x2 = ya + 1 / i;
//	printf("x2 =%f ya(%f)/i(%f)\n", x2, yb, i);
	printf("rot = %f  x1= %.3f x2 = %.3f ya =%.3f\n", t->rot, x1, x2, ya);
}

void		ft_check_vertical_wall(t_t *t)
{
	float 	ya;
	float	yb;
	float 	x1;
	float 	x2;
	double	i;

	printf("vertical\n");
	ya = (t->y - (int)t->y);
	x1 = 0;
	x2 = 0;
	i = tan(t->rot);
	printf("x1 =%f ya(%f)/i(%f)\n", x1, ya, i);
	if (t->rot == (float)M_PI || t->rot == (float)(0))
		i = 1;
	x1 = ya / i;
	printf("x1 =%f ya(%f)/i(%f)\n", x1, ya, i);
	x2 = ya + 1 / i;
	printf("x2 =%f ya(%f)/i(%f)\n", x2, yb, i);
	printf("rot = %f  x1= %.3f x2 = %.3f ya =%.3f\n", t->rot, x1, x2, ya);
}

void		ft_screen(t_t *t)
{
	int		centre;
	float	min;
	float	max;
	int		degre;

	centre = t->win_x/2;
	t->cam_distance = centre / tan(30);
	t->maxray = t->rot + (30 * (M_PI/180));
	t->minray = t->rot - (30 * (M_PI/180));
	degre = t->rot * (180 / M_PI);
	t->y += 0.5;
	t->x += 0.5;
	printf("%f %d\n", t->rot, degre);
	if ((degre >= 45 && degre <= 135) || (degre >= 225 && degre <= 315))
		ft_check_vertical_wall(t);
	else
		ft_check_horizontal_wall(t);
}
