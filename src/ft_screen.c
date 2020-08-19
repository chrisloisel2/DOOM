/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 04:57:07 by lchristo          #+#    #+#             */
/*   Updated: 2020/08/19 16:31:19 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void		ft_check_horizontal_wall(t_t *t, float rot)
{
	float 	xa;
	float 	y1;
	float 	y2;

	if (t->degre < 45 || t->degre > 315)
		rot = M_PI - rot;
	xa = (t->x - (int)t->x);
	y1 = xa * tan(rot);
	t->murx = (t->degre > 90 && t->degre < 270) ? t->x - xa : t->x + xa;
	t->mury = t->y + y1;
	while (t->tb[(int)t->mury][(int)t->murx] != '1' && t->murx > 0 && t->murx < t->maxx)
	{
		t->murx = (t->degre > 90 && t->degre < 270) ? t->x - xa++ : t->x + xa++;
		y2 = xa * tan(rot);
		t->mury = t->y + y2;
	}
	t->distx = t->x - t->murx;
	t->disty = t->y - t->mury;
}

void		ft_check_vertical_wall(t_t *t, float rot)
{
	float 	ya;
	float 	x1;
	float 	x2;

	if (t->degre > 180)
		rot = M_PI - rot;
	ya = (t->y - (int)t->y);
	t->mury = (t->degre < 180) ? t->y + ya : t->y - ya;
	x1 = ya / tan(rot);
	t->murx = t->x + x1;
	while (t->tb[(int)t->mury][(int)t->murx] != '1' && t->mury < t->maxy && t->murx < t->maxx)
	{
		t->mury = (t->degre < 180) ? t->y - ya++ : t->y + ya++;
		x2 = ya / tan(rot);
		t->murx = t->x + x2;
	}
	t->distx = t->x - t->murx;
	t->disty = t->y - t->mury;
}

void		ft_regular_line(t_t *t, float rot)
{
	float	x;
	float	y;

	x = t->x;
	y = t->y;
	while (t->tb[(int)y][(int)x] != '1')	
	{
		if (rot == 90)
			y--;
		if (rot == 270)
			y++;
		if (rot == 0)
			x++;
		if (rot == 180)
			x--;
	}
	t->murx = x;
	t->mury = y;
	t->distx = t->x - t->murx;
	t->disty = t->y - t->mury;
}

void		ft_screen(t_t *t)
{
	float	angle;
	float	min;
	float	max;
	int 	i;

	i = 0;
	t->minray = t->rot - (20 * (M_PI/180));
	t->degre = t->minray * (180 / M_PI);
	angle = 40.0/t->win_x;
	while (i <= t->win_x)
	{
		if (t->degre == 90 || t->degre == 270 || t->degre == 0 || t->degre == 180)
			ft_regular_line(t, t->degre);
		else if ((t->degre >= 45 && t->degre <= 135) || (t->degre >= 225 && t->degre <= 315))
			ft_check_vertical_wall(t, t->minray);
		else
			ft_check_horizontal_wall(t, t->minray);
		ft_collomn(t, i);
		t->minray += (angle * M_PI / 180.0);
		t->degre = t->minray * (180.0 / M_PI);
		i++;
	}
}
