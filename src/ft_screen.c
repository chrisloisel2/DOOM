/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 04:57:07 by lchristo          #+#    #+#             */
/*   Updated: 2021/01/13 17:18:18 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void		ft_screen(t_t *t)
{
	int				x;
	int				texx;
	double			lineheight;

	x = 0;
	while (x < t->win_x)
	{
		ft_setupdda(t, x);
		ft_cheapdda(t, lineheight);
		ft_pixel_texture(t, x);
		x++;
	}
	mlx_put_image_to_window(t->mlx_ptr, t->mlx_win, t->image, 0, 0);
}