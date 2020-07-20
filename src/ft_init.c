/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 01:27:21 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/20 05:49:58 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	ft_floor(data_t *data, parse_t *parse)
{
	int i;
	int y;

	y = 0;
	i = parse->win_x / 2;
	while (i <= parse->win_x)
	{
		while (y <= parse->win_y)
		{
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, y, i, parse->fcolor);
			y++;
		}
		y = 0;
		i++;
	}
}

void	ft_ceiling(data_t *data, parse_t *parse)
{
	int i;
	int y;

	y = 0;
	i = 0;
	while (i <= parse->win_x / 2)
	{
		while (y <= parse->win_y)
		{
			mlx_pixel_put(data->mlx_ptr, data->mlx_win, y, i, parse->ccolor);
			y++;
		}
		y = 0;
		i++;
	}
}

void	ft_display(data_t *data, parse_t *parse)
{
	ft_putcolors(parse);
	ft_ceiling(data, parse);
	ft_floor(data, parse);
}

void	ft_init(data_t *data, parse_t *parse)
{
	parse->win_x = 0;
	parse->win_y = 0;
	parse->ccolor = 0;
	parse->fcolor = 0;
	parse->f1 = 0;
	parse->f2 = 0;
	parse->f3 = 0;
	parse->c1 = 0;
	parse->c2 = 0;
	parse->c3 = 0;
	parse->rot = -1;
	parse->memory = malloc(sizeof(char) * 1);
	parse->memory[0] = '\0';
	parse->no = malloc(sizeof(char) * 1);
	parse->no[0] = '\0';
	parse->so = malloc(sizeof(char) * 1);
	parse->so[0] = '\0';
	parse->we = malloc(sizeof(char) * 1);
	parse->we[0] = '\0';
	parse->ea = malloc(sizeof(char) * 1);
	parse->ea[0] = '\0';
	parse->s = malloc(sizeof(char) * 1);
	parse->s[0] = '\0';
}
