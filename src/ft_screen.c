/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 04:57:07 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/20 06:37:15 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void		ft_check_wall(t_t *t, float y, float x)
{
	while (x <= 5)
	{
		y = x * tanf(t->rot);
		printf("%f  %f\n", t->rot, y);
		x++;
	}
}

void		ft_screen(t_t *t)
{
	float y;
	int x;

	y = 0;
	x = 0;
	ft_check_wall(t, y, x);
}
