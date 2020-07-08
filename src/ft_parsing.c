/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 05:06:46 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/08 05:23:54 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

char	*ft_recup_str(char *str)
{
	int		i;
	int		y;
	char	*tmp;

	y = 0;
	i = 0;
	while (ft_check(str[i]))
		i++;
	while (ft_check(str[y]) == 0 && str[y] != '\0' && str[y] != '\n')
		y++;
	tmp = malloc(sizeof(char) * y + 1);
	while (ft_check(str[i]) == 0 && str[i] != '\0' && str[y] != '\n')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

void	ft_parse_nbr(parse_t *parse, char *line)
{
	int i;

	i = 0;
	if (line[0] == 'R')
	{
		while (line[i - 1] != ' ' && line[i] != '\0')
			i++;
		parse->win_x = ft_atoi(line + i++);
		while (line[i - 1] != ' ' && line[i] != '\0')
			i++;
		parse->win_y = ft_atoi(line + i);
	}
	if (line[0] == 'C' && line[1] == ' ')
	{
		parse->c1 = ft_atoi(line + 2);
		while (line[i - 1] != ',' && line[i] != '\0')
			i++;
		parse->c2 = ft_atoi(line + i++);
		while (line[i - 1] != ',' && line[i] != '\0')
			i++;
		parse->c3 = ft_atoi(line + i);
	}
}

void	ft_parse_text(parse_t *parse, char *line)
{
	int i;

	i = 0;
	if (line[0] == 'N' && line[1] == 'O')
		parse->no = ft_recup_str(line + 3);
	if (line[0] == 'S' && line[1] == 'O')
		parse->so = ft_recup_str(line + 3);
	if (line[0] == 'W' && line[1] == 'E')
		parse->we = ft_recup_str(line + 3);
	if (line[0] == 'E' && line[1] == 'A')
		parse->ea = ft_recup_str(line + 3);
	if (line[0] == 'S' && line[1] == ' ')
		parse->s = ft_recup_str(line + 2);
	if (line[0] == 'F' && line[1] == ' ')
	{
		parse->f1 = ft_atoi(line + 2);
		while (line[i - 1] != ',' && line[i] != '\0')
			i++;
		parse->f2 = ft_atoi(line + i++);
		while (line[i - 1] != ',' && line[i] != '\0')
			i++;
		parse->f3 = ft_atoi(line + i);
	}
}

int		ft_parse(int fd, parse_t *parse)
{
	int		i;
	int		j;
	char	*line;

	j = 0;
	while ((i = get_next_line(fd, &line)) > 0)
	{
		ft_parse_text(parse, line);
		ft_parse_nbr(parse, line);
		ft_scoot(parse, line);
		j++;
	}
	ft_tb_made(parse);
	ft_tb_fill(parse);
	i = 0;
	while (i < parse->taby)
	{
		printf("->%s\n", parse->tb[i]);
		i++;
	}
	return (1);
}
