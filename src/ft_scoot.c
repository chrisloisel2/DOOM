/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scoot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 03:10:08 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/27 08:04:14 by lchristo         ###   ########.fr       */
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

void	ft_search_map(parse_t *parse, t_t *t)
{
	map_t map;

	map.x = 0;
	map.y = 0;
	map.ok = 0;
	map.error = 0;
	ft_perfect_cube(parse, &map, t);
	ft_one(parse, &map, t);
	ft_two(parse, &map, t);
	ft_map_check(parse, &map, t);
	ft_sniff(parse, &map);
}

void	ft_tb_fill(parse_t *parse, t_t *t)
{
	int i;
	int ib;
	int y;

	i = 0;
	y = 0;
	ib = 0;
	while (parse->memory[i] != '\0' && y < t->maxy)
	{
		if (t->demimap == t->maxy && parse->memory[i] == ' ')
			i ++;
		t->tb[y][ib] = parse->memory[i];
		ib++;
		i++;
		if (parse->memory[i] == '\n')
		{
			t->tb[y][ib] = '\0';
			ib = 0;
			i++;
			y++;
		}
	}
}

void	ft_tb_made(parse_t *parse, t_t *t)
{
	int i;
	int p;
	int y;

	y = 0;
	i = 0;
	p = 0;
	while (parse->memory[i] != '\0')
	{
		if (parse->memory[i] == '\n')
			y++;
		i++;
	}
	t->maxy = y;
	t->tb = malloc(sizeof(char *) * y + 1);
	i = 0;
	y = 0;
	while (parse->memory[i] != '\0')
	{
		while (parse->memory[i] != '\n' && parse->memory != '\0')
		{
			y++;
			i++;
		}
		if (t->demimap == t->maxy)
			y = y/2;;
		t->tb[p] = malloc(sizeof(char) * y + 1);
		y = 0;
		i++;
		p++;
	}
}

void	ft_scoot(parse_t *parse, char *line, t_t *t)
{
	int		i;
	char	str[2];
	char	*leaks;

	str[0] = '\n';
	str[1] = '\0';
	i = 1;
	while (line[i] != '\0' && line[i + 2] == line[i] && line[i] == ' ')
		i += 2;
	if (i == ft_strlen(line) - 2)
		t->demimap++;
	printf("demimap = %d\n", t->demimap);
	i = 0;
	while (ft_white_space(line[i]))
		i++;
	if (line[i] == '1' || line[i] == '0')
	{
		parse->memory = ft_strjoin(parse->memory, line);
		parse->memory = ft_strjoin(parse->memory, str);
	}
}
