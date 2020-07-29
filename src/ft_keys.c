/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 14:23:54 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/29 15:56:49 by lchristo         ###   ########.fr       */
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
	xa = (t->x - (int)t->x);
	y1 = xa * tan(rot);
	xdiff = (degre > 90 && degre < 270) ? t->x - xa++ : t->x + xa;
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
	ya = (t->y - (int)t->y);
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
	if (c == W && t->tb[(int)t->y - 1][(int)t->x] == '0')
		ft_trigo(t, t->rot);
	if (c == A && t->tb[(int)t->y][(int)t->x - 1] == '0')
		ft_trigo(t, t->rot - (M_PI/2));
	if (c == S && t->tb[(int)t->y + 1][(int)t->x] == '0')
		ft_trigo(t, t->rot + M_PI);
	if (c == D && t->tb[(int)t->y][(int)t->x + 1] == '0')
		ft_trigo(t, t->rot + (M_PI/2));
	if (c == RIGHT)
		t->rot += (float)(20 * M_PI / 180);	
	if (c == LEFT)
		t->rot -= (float)(20 * M_PI / 180);	
	if (t->rot > (float)(2 * M_PI))
		t->rot -= (float)(2*M_PI);
	if (t->rot < (float)(0))
		t->rot += (float)(2*M_PI);
	t->degre = t->rot * (180/M_PI);
	ft_screen(t);
	return (0);
}
