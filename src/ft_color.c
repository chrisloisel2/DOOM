/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 00:15:52 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/08 02:42:00 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	ft_putcolors(parse_t *parse)
{
	parse->fcolor = parse->f1;
	parse->fcolor = (parse->fcolor << 8) + parse->f2;
	parse->fcolor = (parse->fcolor << 8) + parse->f3;
	parse->ccolor = parse->c1;
	parse->ccolor = (parse->ccolor << 8) + parse->c2;
	parse->ccolor = (parse->ccolor << 8) + parse->c3;
}
