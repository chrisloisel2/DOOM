/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scoot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 03:10:08 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/20 05:50:42 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

int		ft_sniff(parse_t *parse, map_t *map)
{
	if (map->error == 1)
	{
		ft_printf("map error\n");
		return (1);
	}
	else
	{
		ft_printf("map ok\n");
		return (0);
	}
}

void	ft_search_map(parse_t *parse)
{
	map_t map;

	map.x = 0;
	map.y = 0;
	map.ok = 0;
	map.error = 0;
	parse->posx = 0;
	parse->posy = 0;
	ft_perfect_cube(parse, &map);
	ft_one(parse, &map);
	ft_two(parse, &map);
	ft_map_check(parse, &map);
	ft_sniff(parse, &map);
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
	while (ft_white_space(line[i]))
		i++;
	if (line[i] == '1' || line[i] == '0')
	{
		parse->memory = ft_strjoin(parse->memory, line);
		parse->memory = ft_strjoin(parse->memory, str);
	}
}
