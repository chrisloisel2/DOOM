/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 01:27:21 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/23 07:13:52 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	ft_floor(data_t *data, t_t *t)
{
	int i;
	int y;

	y = 0;
	i = t->win_x / 2;
	while (i <= t->win_x)
	{
		while (y <= t->win_y)
		{
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, y, i, t->fcolor);
			y++;
		}
		y = 0;
		i++;
	}
}

void	ft_ceiling(data_t *data, t_t *t)
{
	int i;
	int y;

	y = 0;
	i = 0;
	while (i <= t->win_x / 2)
	{
		while (y <= t->win_y)
		{
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, y, i, t->ccolor);
			y++;
		}
		y = 0;
		i++;
	}
}

void	ft_display(data_t *data, parse_t *parse, t_t *t)
{
	ft_putcolors(t);
	ft_ceiling(data, t);
	ft_floor(data, t);
}

void	ft_init(data_t *data, parse_t *parse, t_t *t)
{
	t->minray = 0;
	t->maxray = 0;
	t->x = 0;
	t->y = 0;
	t->rot = 0;
	t->win_x = 0;
	t->win_y = 0;
	t->ccolor = 0;
	t->fcolor = 0;
	t->f1 = 0;
	t->f2 = 0;
	t->f3 = 0;
	t->c1 = 0;
	t->c2 = 0;
	t->c3 = 0;
	parse->memory = malloc(sizeof(char) * 1);
	parse->memory[0] = '\0';
	t->no = malloc(sizeof(char) * 1);
	t->no[0] = '\0';
	t->so = malloc(sizeof(char) * 1);
	t->so[0] = '\0';
	t->we = malloc(sizeof(char) * 1);
	t->we[0] = '\0';
	t->ea = malloc(sizeof(char) * 1);
	t->ea[0] = '\0';
	t->s = malloc(sizeof(char) * 1);
	t->s[0] = '\0';
}
