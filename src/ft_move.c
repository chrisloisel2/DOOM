/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 20:11:48 by lchristo          #+#    #+#             */
/*   Updated: 2021/01/05 20:26:16 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	ft_arriere(t_t *t, double vitesse)
{
	double y;
	double x;

	y = t->y - (t->diry * vitesse);
	x = t->x - (t->dirx * vitesse);
	if (t->tb[(int)y][(int)x] == '0')
	{
		t->y = y;
		t->x = x;
	}
}

void	ft_droite(t_t *t, double vitesse)
{
	double y;
	double x;

	y = t->y - (double)((t->diry + 1) * vitesse);
	x = t->x - (double)((t->dirx + 1) * vitesse);
	if (t->tb[(int)y][(int)x] == '0')
	{
		t->y = y;
		t->x = x;
	}
}

void	ft_gauche(t_t *t, double vitesse)
{
	double y;
	double x;

	y = t->y + (double)((t->diry + 1) * vitesse);
	x = t->x + (double)((t->dirx + 1) * vitesse);
	if (t->tb[(int)y][(int)x] == '0')
	{
		t->y = y;
		t->x = x;
	}
}

void	ft_avant(t_t *t, double vitesse)
{
	double y;
	double x;

	y = t->y + (t->diry * vitesse);
	x = t->x + (t->dirx * vitesse);
	if (t->tb[(int)y][(int)x] == '0')
	{
		t->y = y;
		t->x = x;
	}
}

void	ft_rot(t_t *t, double r)
{
	double olddirx;
	double oldplanex;

	olddirx = t->dirx;
	oldplanex = t->planex;
	t->dirx = t->dirx * cos(r) - t->diry * sin(r);
	t->diry = olddirx * sin(r) + t->diry * cos(r);
	t->planex = t->planex * cos(r) - t->planey * sin(r);
	t->planey = oldplanex * sin(r) + t->planey * cos(r);
}
