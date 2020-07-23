/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 04:57:07 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/23 18:03:44 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void		ft_check_horizontal_wall(t_t *t, float rot)
{
	float 	ya;
	float 	x1;
	float 	x2;
	int 	xdiff;
	int 	ydiff;

	ya = (t->x - (int)t->x);
	x1 = ya / tan(rot);
	xdiff = (t->degre > 90 && t->degre < 270) ? t->x - x1 : t->x + x1;
	ydiff = t->y + ya;
	printf("%d/%d\n", ydiff, xdiff);
	if (t->tb[ydiff][xdiff] == '0')
		t->tb[ydiff][xdiff] = ' ';
	ydiff = t->y + ya++;
	x2 = ya / tan(rot);
	xdiff = (t->degre > 90 && t->degre < 270) ? t->x - x2 : t->x + x2;
	while (t->tb[ydiff][xdiff] != '1')
	{
		printf("%d/%d\n", ydiff, xdiff);
		ydiff = t->y + ya++;
		x2 = ya / tan(rot);
		xdiff = (t->degre > 90 && t->degre < 270) ? t->x - x2 : t->x + x2;
		if (t->tb[ydiff][xdiff] == '0')
			t->tb[ydiff][xdiff] = ' ';
	}
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
		if (rot == 90)
			y--;
		if (rot == 270)
			y++;
		if (rot == 0)
			x++;
		if (rot == 180)
			x--;
	}
}

void		ft_check_vertical_wall(t_t *t, float rot)
{
	float 	ya;
	float 	x1;
	float 	x2;
	int 	xdiff;
	int 	ydiff;

	ya = (t->y - (int)t->y);
	x1 = ya / tan(rot);
	xdiff = t->x + x1;
	ydiff = (t->degre < 180) ? t->y - ya : t->y + ya;
	if (t->tb[ydiff][xdiff] == '0')
		t->tb[ydiff][xdiff] = ' ';
	ydiff = (t->degre < 180) ? t->y - ya++ : t->y + ya++;
	x2 = ya / tan(rot);
	xdiff = t->x + x2;
	while (t->tb[ydiff][xdiff] != '1')
	{
		ydiff = (t->degre < 180) ? t->y - ya++ : t->y + ya++;
		x2 = ya / tan(rot);
		xdiff = t->x + x2;
		if (t->tb[ydiff][xdiff] == '0')
			t->tb[ydiff][xdiff] = ' ';
	}
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
	t->x += 0.5;
	t->y += 0.5;
	degre = t->maxray;
	angle = 60.0/t->win_x;
	t->degre = degre;
//	printf("degré %d  minray = %f  angle =%.15f\n", degre, t->minray, angle);
	while (i <= t->win_x)
	{
		if (degre == 90 || degre == 270 || degre == 0 || degre == 180)
			ft_regular_line(t, degre);
		else if ((degre >= 45 && degre <= 135) || (degre >= 225 && degre <= 315))
			ft_check_vertical_wall(t, t->minray);
		else
			ft_check_horizontal_wall(t, t->minray);
		t->minray += (angle * M_PI / 180.0);
		t->maxray = t->minray * (180.0 / M_PI);
		degre = t->maxray;
		t->degre = degre;
		i++;
	}
	i = 0;
	while (i < t->maxy)
	{
		printf("%s\n", t->tb[i]);
		i++;
	}
}
