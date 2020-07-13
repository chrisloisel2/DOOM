/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scoot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 03:10:08 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/13 13:48:38 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

int		ft_one(parse_t *parse, map_t *map, int y, int x)
{
	if (parse->tb[y][x] == '\0')
		return (0);
	if (parse->tb[y][x] == ' ')
		(map->x < x) ? x++ : x--;
	if (parse->tb[y][x] == '1')
	{
		map->x = x;
		map->y = y;
		return (1);
	}
	return (0);
}

int		ft_sniff(parse_t *parse, map_t *map)
{
	if (ft_one(parse, map, map->y, map->x))
		return (1);
	if (map->y < parse->taby - 1 && ft_one(parse, map, map->y + 1, map->x))
		return (1);
	if (map->x > 0 && ft_one(parse, map, map->y, map->x - 1))
		return (1);
	if (ft_one(parse, map, map->y, map->x + 1))
		return (1);
	if (map->y > 0 && ft_one(parse, map, map->y - 1, map->x))
		return (1);
	return (0);
}

void	ft_check_sniff(parse_t *parse)
{

}

void	ft_search_map(parse_t *parse)
{
	map_t map;

	map.x = 0;
	map.y = 0;
	map.ok = 0;
	while (ft_sniff(parse, &map))
	{
		parse->tb[map.y][map.x] = 'X';
	}
	ft_check_sniff(parse);
}

void	ft_tb_fill(parse_t *parse)
{
	int i;
	int ib;
	int y;

	i = 0;
	y = 0;
	ib = 0;
	while (parse->memory[i] != '\0' && y < parse->taby)
	{
		parse->tb[y][ib] = parse->memory[i];
		ib++;
		i++;
		if (parse->memory[i] == '\n')
		{
			parse->tb[y][ib] = '\0';
			ib = 0;
			i++;
			y++;
		}
	}
}

void	ft_tb_made(parse_t *parse)
{
	int i;
	int t;
	int y;

	y = 0;
	i = 0;
	t = 0;
	while (parse->memory[i] != '\0')
	{
		if (parse->memory[i] == '\n')
			y++;
		i++;
	}
	parse->taby = y;
	parse->tb = malloc(sizeof(char *) * y + 1);
	i = 0;
	y = 0;
	while (parse->memory[i] != '\0')
	{
		while (parse->memory[i] != '\n' && parse->memory != '\0')
		{
			y++;
			i++;
		}
		parse->tb[t] = malloc(sizeof(char) * y + 1);
		y = 0;
		i++;
		t++;
	}
}

void	ft_scoot(parse_t *parse, char *line)
{
	int		i;
	char	str[2];
	char	*leaks;

	str[0] = '\n';
	str[1] = '\0';
	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '1')
	{
		parse->memory = ft_strjoin(parse->memory, line);
		parse->memory = ft_strjoin(parse->memory, str);
	}
}
