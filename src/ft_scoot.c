/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scoot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 03:10:08 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/08 05:24:13 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

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
