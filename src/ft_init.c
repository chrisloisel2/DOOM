/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 01:27:21 by lchristo          #+#    #+#             */
/*   Updated: 2020/08/17 15:32:18 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	ft_floor(t_t *t)
{
	int i;
	int i2;
	int y;

	i2 = 0;
	y = t->win_y / 2;
	i = t->win_x * y;
	while (y < t->win_y)
	{
		while (i2 < t->win_x)
		{
			t->si[i] = t->fcolor;
			i++;
			i2++;
		}
		i2 = 0;
		y++;
	}
}

void	ft_ceiling(t_t *t)
{
	int i;
	int i2;
	int y;

	i2 = 0;
	y = 0;
	i = 0;
	while (y < t->win_y / 2)
	{
		while (i2 < t->win_x)
		{
			t->si[i] = t->ccolor;
			i++;
			i2++;
		}
		i2 = 0;
		y++;
	}
}

void	ft_display(t_t *t)
{
	int huit;
	int un;
	int sl;

	un = 1;
	huit = 3;
	sl = t->win_x;
	t->image = mlx_new_image(t->mlx_ptr, t->win_x, t->win_y);
	t->si = (unsigned int *)mlx_get_data_addr(t->image, &huit, &sl, &un);
	ft_putcolors(t);
	ft_ceiling(t);
	ft_floor(t);
}

void	ft_init(parse_t *parse, t_t *t)
{
	t->image = 0;
	t->demimap = 0;
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
