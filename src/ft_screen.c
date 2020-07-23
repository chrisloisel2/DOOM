/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 04:57:07 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/23 13:33:53 by lchristo         ###   ########.fr       */
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

void		ft_regular_line(t_t *t)
{
	float	x;
	float	y;

	x = t->x;
	y = t->y;
	while (t->tb[(int)y][(int)x] != '1')	
	{
		if (t->tb[(int)y][(int)x] == '0')
			t->tb[(int)y][(int)x] = ' ';
		if (t->degre == 90)
			y--;
		if (t->degre == 270)
			y++;
		if (t->degre == 0)
			x++;
		if (t->degre == 180)
			x--;
	}
	x -= t->x;
	y -= t->y;
	printf("[%f][%f]\n", y, x);
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
	int 	i;

	i = 0;
	centre = t->win_x/2;
	t->cam_distance = centre / tan(30);
	t->maxray = t->rot + (30 * (M_PI/180));
	t->minray = t->rot - (30 * (M_PI/180));
	t->degre = t->rot * (180 / M_PI);

//	t->y += 0.5;
//	t->x += 0.5;
	while (i <= t->win_x)
	{
		if (t->degre == 90 || t->degre == 270 || t->degre == 0 || t->degre == 180)
			ft_regular_line(t);
		else if ((t->degre >= 45 && t->degre <= 135) || (t->degre >= 225 && t->degre <= 315))
			ft_check_vertical_wall(t);
		else
			ft_check_horizontal_wall(t);
		t->minray += ((60/t->win_x) * M_PI / 180);
		i++;
	}
	i = 0;
	while (i < t->maxy)
	{
		printf("%s\n", t->tb[i]);
		i++;
	}
}
