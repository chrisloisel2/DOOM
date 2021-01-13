/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 05:06:46 by lchristo          #+#    #+#             */
/*   Updated: 2021/01/05 20:39:26 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	ft_two(parse_t *parse, map_t *map, t_t *t)
{
	int x;
	int y;

	x = ft_strlen(t->tb[y]) - 1;
	y = 0;
	while (y < t->maxy - 1)
	{
		while (x < ft_strlen(t->tb[y]) && ft_white_space(t->tb[y][x]))
			x--;
		if (t->tb[y][x] != '1')
			map->error = 1;
		y++;
		x = ft_strlen(t->tb[y]) - 1;
	}
	y = t->maxy - 1;
	x = 0;
	while (x < ft_strlen(t->tb[t->maxy - 1]))
	{
		while (y > 1 && ft_white_space(t->tb[y][x]))
			y--;
		if (y != 1 && t->tb[y][x] != '1')
			map->error = 1;
		x++;
		y = t->maxy - 1;
	}
}

void	ft_one(parse_t *parse, map_t *map, t_t *t)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < ft_strlen(t->tb[0]))
	{
		while (y < t->maxy - 1 && ft_white_space(t->tb[y][x]))
			y++;
		if (y < t->maxy - 1 && x < ft_strlen(t->tb[y]) &&
				t->tb[y][x] != '1')
			map->error = 1;
		x++;
		y = 0;
	}
	x = 0;
	y = 0;
	while (y < t->maxy - 1)
	{
		while (t->tb[y][x] != '\0' && ft_white_space(t->tb[y][x]))
			x++;
		(t->tb[y][x] != '1') ? map->error = 1 : 0;
		x = 0;
		y++;
	}
}

void	ft_perfect_cube(parse_t *parse, map_t *map, t_t *t)
{
	int		i;
	char	s[2];

	s[0] = ' ';
	s[1] = '\0';
	i = 0;
	while (map->y < t->maxy - 1)
	{
		if (i < ft_strlen(t->tb[map->y]))
			i = ft_strlen(t->tb[map->y]);
		map->y++;
	}
	t->maxx = i;
	map->y = 0;
	while (map->y < t->maxy)
	{
		while (i > ft_strlen(t->tb[map->y]))
			t->tb[map->y] = ft_strjoin(t->tb[map->y], s);
		map->y++;
	}
}

int		ft_get_player(char c, t_t *t)
{
	if (c == 'N')
	{
		t->diry = -1.0;
		t->dirx = 0.0;
		return (1);
	}
	if (c == 'E')
	{
		t->diry = 0.0;
		t->dirx = 1.0;
		return (1);
	}
	if (c == 'S')
	{
		t->diry = 1.0;
		t->dirx = 0.0;
		return (1);
	}
	if (c == 'W')
	{
		t->diry = 0.0;
		t->dirx = -1.0;
		return (1);
	}
	return (0);
}

void	ft_map_check(parse_t *parse, map_t *map, t_t *t)
{
	int x;
	int y;
	int r;

	r = 0;
	x = 0;
	y = 0;
	while (y < t->maxy - 1)
	{
		while (x < t->maxx)
		{
			if (ft_get_player(t->tb[y][x], t) == 1)
			{
				r++;
				t->x = x;
				t->y = y;
				t->tb[y][x] = '0';
			}
			(r > 1) ? map->error = 1 : 0;
			x++;
		}
		x = 0;
		y++;
	}
	(r == 0) ? map->error = 1 : 0;
}
