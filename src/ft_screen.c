/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 04:57:07 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/23 14:44:03 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void		ft_check_horizontal_wall(t_t *t, float rot)
{
	float 	ya;
	float 	x1;
	float 	x2;
	float 	xdiff;

	ya = (t->x - (int)t->x);
	x1 = ya / tan(rot);
	ya++;
	x2 = ya / tan(rot);
	if (t->tb[(int)(t->y + ya)][(int)(t->x + xdiff)] == '0')
		t->tb[(int)(t->y + ya)][(int)(t->x + xdiff)] = ' ';
	if (t->tb[(int)(t->y + ya)][(int)(t->x + x1)] == '1')
		return ;
	while (t->tb[(int)(t->y + ya)][(int)(t->x + x2)] == '1')
	{
		if (t->tb[(int)(t->y + ya)][(int)(t->x + xdiff)] == '0')
			t->tb[(int)(t->y + ya)][(int)(t->x + xdiff)] = ' ';
		ya++;
		x2 = ya / tan(rot);
	}
//	printf("x1 =%f ya(%f)/i(%f)\n", x1, ya, i);
//	printf("x2 =%f ya(%f)/i(%f)\n", x2, yb, i);
//	printf("rot = %f  x1= %.3f x2 = %.3f ya =%.3f\n", t->rot, x1, x2, ya);
}

void		ft_regular_line(t_t *t, float rot)
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
}

void		ft_check_vertical_wall(t_t *t, float rot)
{
	float 	ya;
	float 	x1;
	float 	x2;
	float 	xdiff;

//	printf("vertical\n");
	ya = (t->y - (int)t->y);
	x1 = ya / tan(rot);
	if (t->tb[(int)(t->y + ya)][(int)(t->x + x1)] == '1')
		return ;
	ya++;
	x2 = ya / tan(rot);
	if (t->tb[(int)(t->y + ya)][(int)(t->x + xdiff)] == '0')
		t->tb[(int)(t->y + ya)][(int)(t->x + xdiff)] = ' ';
	while (t->tb[(int)(t->y + ya)][(int)(t->x + x2)] == '1')
	{
		if (t->tb[(int)(t->y + ya)][(int)(t->x + xdiff)] == '0')
			t->tb[(int)(t->y + ya)][(int)(t->x + xdiff)] = ' ';
		ya++;
		x2 = ya / tan(rot);
	}
//	printf("x1 =%f ya(%f)/i(%f)\n", x1, ya, i);
//	printf("x2 =%f ya(%f)/i(%f)\n", x2, yb, i);
//	printf("rot = %f  x1= %.3f x2 = %.3f ya =%.3f\n", t->rot, x1, x2, ya);
}

void		ft_screen(t_t *t)
{
	float	angle;
	float	min;
	float	max;
	int 	i;
	int 	degre;

	i = 0;
	t->cam_distance = (t->win_x/2) / tan(30);
	t->minray = t->rot - (30 * (M_PI/180));
	t->maxray = t->minray * (180 / M_PI);
	degre = t->maxray;
	angle = fmod(60, t->win_x);
	printf("degré %d  minray = %f  angle =%.15f\n", degre, t->minray, angle);
	while (i <= t->win_x)
	{
		if (degre == 90 || degre == 270 || degre == 0 || degre == 180)
			ft_regular_line(t, t->minray);
		else if ((degre >= 45 && degre <= 135) || (degre >= 225 && degre <= 315))
			ft_check_vertical_wall(t, t->minray);
		else
			ft_check_horizontal_wall(t, t->minray);
		t->minray = (angle * M_PI / 180);
		t->maxray = t->minray * (180 / M_PI);
		degre = (int)t->maxray;
		i++;
	}
	i = 0;
	while (i < t->maxy)
	{
		printf("%s\n", t->tb[i]);
		i++;
	}
}
