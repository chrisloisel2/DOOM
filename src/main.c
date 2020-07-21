/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 22:01:44 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/21 01:01:02 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

int		ft_putkey(int c, t_t *t)
{
	printf("[%f, %f]\n", t->y, t->x);
	if (c == W)
		t->x += 0.25;
	if (c == A)
		t->y -= 0.25;
	if (c == S)
		t->x -= 0.25;
	if (c == D)
		t->y += 0.25;
	return (0);
}

void	ft_start(data_t *data, parse_t *parse, t_t *t)
{

	printf("[%f, %f]\n", t->y, t->x);
	ft_screen(t);
//	data->mlx_ptr = mlx_init();
//	data->mlx_win = mlx_new_window(data->mlx_ptr, parse->win_x, parse->win_y, "DOOM");
//	ft_display(data, parse);
//	mlx_hook(data->mlx_win, 2, 0, ft_putkey, &t);
//	mlx_loop(data->mlx_ptr);
}

int		main(int argc, char **argv)
{
	t_t			t;
	data_t		data;
	parse_t		parse;
	int			fd;

	fd = 0;
	ft_init(&data, &parse, &t);
	if (!(fd = open(argv[1], O_RDONLY)))
		ft_printf("map error");
	if (argc == 2 && ft_parse(fd, &parse, &t) == 1)
		ft_start(&data, &parse, &t);
	else
		ft_printf("map error");
	return (EXIT_SUCCESS);
}
