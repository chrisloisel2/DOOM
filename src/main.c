/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 22:01:44 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/29 14:48:27 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	ft_start(parse_t *parse, t_t *t)
{
	t->mlx_ptr = mlx_init();
	t->mlx_win = mlx_new_window(t->mlx_ptr, t->win_x, t->win_y, "DOOM");
	ft_display(t);
	ft_screen(t);
	mlx_hook(t->mlx_win, 2, 0, ft_putkey, t);
	mlx_loop(t->mlx_ptr);
}

int		main(int argc, char **argv)
{
	t_t			t;
	parse_t		parse;
	int			fd;

	fd = 0;
	ft_init(&parse, &t);
	if (!(fd = open(argv[1], O_RDONLY)))
		ft_printf("map error");
	if (argc == 2 && ft_parse(fd, &parse, &t) == 1)
		ft_start(&parse, &t);
	else
		ft_printf("map error");
	return (EXIT_SUCCESS);
}
