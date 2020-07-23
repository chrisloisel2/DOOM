/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 05:06:46 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/23 03:43:11 by lchristo         ###   ########.fr       */
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

void	ft_parse_nbr(t_t *t, char *line)
{
	int i;

	i = 0;
	if (line[0] == 'R')
	{
		while (line[i - 1] != ' ' && line[i] != '\0')
			i++;
		t->win_x = ft_atoi(line + i++);
		while (line[i - 1] != ' ' && line[i] != '\0')
			i++;
		t->win_y = ft_atoi(line + i);
	}
	if (line[0] == 'C' && line[1] == ' ')
	{
		t->c1 = ft_atoi(line + 2);
		while (line[i - 1] != ',' && line[i] != '\0')
			i++;
		t->c2 = ft_atoi(line + i++);
		while (line[i - 1] != ',' && line[i] != '\0')
			i++;
		t->c3 = ft_atoi(line + i);
	}
}

void	ft_parse_text(t_t *t, char *line)
{
	int i;

	i = 0;
	if (line[0] == 'N' && line[1] == 'O')
		t->no = ft_recup_str(line + 3);
	if (line[0] == 'S' && line[1] == 'O')
		t->so = ft_recup_str(line + 3);
	if (line[0] == 'W' && line[1] == 'E')
		t->we = ft_recup_str(line + 3);
	if (line[0] == 'E' && line[1] == 'A')
		t->ea = ft_recup_str(line + 3);
	if (line[0] == 'S' && line[1] == ' ')
		t->s = ft_recup_str(line + 2);
	if (line[0] == 'F' && line[1] == ' ')
	{
		t->f1 = ft_atoi(line + 2);
		while (line[i - 1] != ',' && line[i] != '\0')
			i++;
		t->f2 = ft_atoi(line + i++);
		while (line[i - 1] != ',' && line[i] != '\0')
			i++;
		t->f3 = ft_atoi(line + i);
	}
}

int		ft_parse(int fd, parse_t *parse, t_t *t)
{
	int		i;
	int		j;
	char	*line;

	j = 0;
	while ((i = get_next_line(fd, &line)) > 0)
	{
		ft_parse_text(t, line);
		ft_parse_nbr(t, line);
		ft_scoot(parse, line, t);
		j++;
	}
	ft_tb_made(parse, t);
	ft_tb_fill(parse, t);
	ft_search_map(parse, t);
	i = 0;
	while (i < t->maxy)
	{
		printf("->%s\n", t->tb[i]);
		i++;
	}
	return (1);
}
