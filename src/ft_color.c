/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 00:15:52 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/23 03:31:23 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	ft_putcolors(t_t *t)
{
	t->fcolor = t->f1;
	t->fcolor = (t->fcolor << 8) + t->f2;
	t->fcolor = (t->fcolor << 8) + t->f3;
	t->ccolor = t->c1;
	t->ccolor = (t->ccolor << 8) + t->c2;
	t->ccolor = (t->ccolor << 8) + t->c3;
}
