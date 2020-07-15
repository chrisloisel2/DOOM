/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scoot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 03:10:08 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/15 02:20:21 by lchristo         ###   ########.fr       */
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
		if (y < parse->taby - 1 && x < ft_strlen(parse->tb[y]) && parse->tb[y][x] != '1')
		{
			printf("1 ere boucle x=%d y=%d\n", x, y);
			map->error = 1;
		}
		x++;
		y = 0;
	}
	x = 0;
	y = 0;
	while (y < parse->taby - 1)
	{
		while (parse->tb[y][x] != '\0' && ft_white_space(parse->tb[y][x]))
			x++;
		if (parse->tb[y][x] != '1')
		{
			printf("2 eme boucle x=%d y=%d\n", x, y);
			map->error = 1;
		}
		x = 0;
		y++;
	}
	x = ft_strlen(parse->tb[y]) - 1;
	y = 0;
	while (y < parse->taby - 1)
	{
		while (x < ft_strlen(parse->tb[y]) && ft_white_space(parse->tb[y][x]))
			x--;
		if (parse->tb[y][x] != '1')
		{
			printf("3eme boucle x=%d y=%d\n", x, y);
			map->error = 1;
		}
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
		{
			printf("4 eme boucle x=%d y=%d\n", x, y);
			map->error = 1;
		}
		x++;
		y = parse->taby - 1;
	}
}

void	ft_sniff(parse_t *parse, map_t *map)
{
	ft_one(parse, map);
	if (map->error == 1)
		ft_printf("map error\n");
	else
		ft_printf("map ok\n");
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
	map.error = 0;
	ft_sniff(parse, &map);
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
