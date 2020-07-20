/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 05:06:46 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/20 05:49:18 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

int		ft_white_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f' ||
			c == '\r')
		return (1);
	return (0);
}

void	ft_two(parse_t *parse, map_t *map)
{
	int x;
	int y;

	x = ft_strlen(parse->tb[y]) - 1;
	y = 0;
	while (y < parse->taby - 1)
	{
		while (x < ft_strlen(parse->tb[y]) && ft_white_space(parse->tb[y][x]))
			x--;
		if (parse->tb[y][x] != '1')
			map->error = 1;
		y++;
		x = ft_strlen(parse->tb[y]) - 1;
	}
	y = parse->taby - 1;
	x = 0;
	while (x < ft_strlen(parse->tb[parse->taby - 1]))
	{
		while (y > 1 && ft_white_space(parse->tb[y][x]))
			y--;
		if (y != 1 && parse->tb[y][x] != '1')
			map->error = 1;
		x++;
		y = parse->taby - 1;
	}
}

void	ft_one(parse_t *parse, map_t *map)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < ft_strlen(parse->tb[0]))
	{
		while (y < parse->taby - 1 && ft_white_space(parse->tb[y][x]))
			y++;
		if (y < parse->taby - 1 && x < ft_strlen(parse->tb[y]) &&
				parse->tb[y][x] != '1')
			map->error = 1;
		x++;
		y = 0;
	}
	x = 0;
	y = 0;
	while (y < parse->taby - 1)
	{
		while (parse->tb[y][x] != '\0' && ft_white_space(parse->tb[y][x]))
			x++;
		(parse->tb[y][x] != '1') ? map->error = 1 : 0;
		x = 0;
		y++;
	}
}

void	ft_perfect_cube(parse_t *parse, map_t *map)
{
	int		i;
	char	s[2];

	s[0] = ' ';
	s[1] = '\0';
	i = 0;
	while (map->y < parse->taby - 1)
	{
		if (i < ft_strlen(parse->tb[map->y]))
			i = ft_strlen(parse->tb[map->y]);
		map->y++;
	}
	map->max = i;
	map->y = 0;
	while (map->y < parse->taby)
	{
		while (i > ft_strlen(parse->tb[map->y]))
			parse->tb[map->y] = ft_strjoin(parse->tb[map->y], s);
		map->y++;
	}
}

int		ft_get_player(char c, parse_t *parse)
{
	if (c == 'N')
		parse->rot = 90;
	if (c == 'E')
		parse->rot = 180;
	if (c == 'S')
		parse->rot = -180;
	if (c == 'W')
		parse->rot = 0;
	if (c == parse->rot && c != -1)	
		return (1);
	return (0);
}

void	ft_map_check(parse_t *parse, map_t *map)
{
	int x;
	int y;
	int r;

	r = 0;
	x = 0;
	y = 0;
	while (y < parse->taby - 1)
	{
		while (x < map->max)
		{
			if (ft_get_player(parse->tb[y][x], parse) == 1)
			{
				r++;
				parse->posx = x;
				parse->posy = y;
			}
			(r > 1) ? map->error = 1 : 0;
			x++;
		}
		x = 0;
		y++;
	}
	(parse->rot == -1) ? map->error = 1 : 0;
}
