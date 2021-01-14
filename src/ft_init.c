/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 01:27:21 by lchristo          #+#    #+#             */
/*   Updated: 2020/08/20 13:54:17 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	ft_init(parse_t *parse, t_t *t)
{
	t->image = 0;
	t->demimap = 0;
	t->x = 0;
	t->y = 0;
	t->win_x = 0;
	t->win_y = 0;
	t->ccolor = 0;
	t->fcolor = 0;
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
