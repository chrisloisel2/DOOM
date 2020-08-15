/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 14:23:54 by lchristo          #+#    #+#             */
/*   Updated: 2020/08/12 18:41:21 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void		ft_horizontal(t_t *t, float rot, int degre)
{
	float 	xa;
	float 	y1;
	float 	y2;
	int 	xdiff;
	int 	ydiff;

	if (degre < 45 || degre > 315)
		rot = M_PI - rot;
	xa = 1;
	y1 = xa * tan(rot);
	xdiff = (degre > 90 && degre < 270) ? t->x - xa : t->x + xa;
	ydiff = t->y + y1;
	while (xa < 2)
	{
		xdiff = (degre > 90 && degre < 270) ? t->x - xa++ : t->x + xa++;
		y2 = xa * tan(rot);
		ydiff = t->y + y2;
	}
	t->y = ydiff;
	t->x = xdiff;
}

void		ft_vertical(t_t *t, float rot, int degre)
{
	float 	ya;
	float 	x1;
	float 	x2;
	int 	xdiff;
	int 	ydiff;

	if (degre > 180)
		rot = M_PI - rot;
	ya = 1;
	ydiff = (degre < 180) ? t->y + ya : t->y - ya;
	x1 = ya / tan(rot);
	xdiff = t->x + x1;
	while (ya < 2)
	{
		ydiff = (degre < 180) ? t->y - ya++ : t->y + ya++;
		x2 = ya / tan(rot);
		xdiff = t->x + x2;
	}
	t->y = ydiff;
	t->x = xdiff;
}

void	ft_regular(t_t *t, int degre)
{
	if (degre == 270)
		t->y++;
	if (degre == 90)
		t->y--;
	if (degre == 0)
		t->x++;
	if (degre == 180)
		t->x--;
}

void	ft_trigo(t_t *t, float rot)
{
	int degre;

	(rot >= (float)(2 * M_PI)) ? rot -= (float)(2*M_PI) : 0;
	(rot <= (float)(0)) ? rot = (float)(2*M_PI)  : 0;
	degre = rot * (180 / M_PI);
	if (degre == 90 || degre == 270 || degre == 0 || degre == 180)
		ft_regular(t, degre);
	else if ((degre >= 45 && degre <= 135) || (degre >= 225 && degre <= 315))
		ft_vertical(t, rot, degre);
	else
		ft_horizontal(t, rot, degre);
}

int		ft_putkey(int c, t_t *t)
{
	int x;
	int y;

	x = t->x;
	y = t->y;
	(c == W) ? ft_trigo(t, t->rot) : 0;
	(c == A) ? ft_trigo(t, t->rot - (M_PI/4)) : 0;
	(c == S) ? ft_trigo(t, t->rot + M_PI) : 0;
	(c == D) ? ft_trigo(t, t->rot + (M_PI/4)) : 0;
	if (c == ESC)
		t->esc = 1;
	else
		t->esc = 0;
	printf("->%d\n", t->esc);
	(c == RIGHT) ? t->rot += (float)(10 * M_PI / 180) : 0;	
	(c == LEFT) ? t->rot -= (float)(10 * M_PI / 180) : 0;	
	(t->rot > (float)(2 * M_PI)) ? t->rot -= (float)(2*M_PI) : 0;
	(t->rot < (float)(0)) ? t->rot += (float)(2*M_PI) : 0 ;
	t->degre = t->rot * (180/M_PI);
	if (t->tb[(int)t->y][(int)t->x] == '1')
	{
		t->y = y;
		t->x = x;
	}
	ft_screen(t);
	return (0);
}
