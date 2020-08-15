/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 22:01:44 by lchristo          #+#    #+#             */
/*   Updated: 2020/08/15 18:33:22 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	ft_start(parse_t *parse, t_t *t)
{
	int huit;
	int un;
	int l;
	int h;
	int sl;

	l = t->mur_h;
	h = 894;
	sl = 894;
	huit = 3;
	un = 1;
	t->mlx_ptr = mlx_init();
	t->mlx_win = mlx_new_window(t->mlx_ptr, t->win_x, t->win_y, "DOOM");
	ft_display(t);
	ft_screen(t);
	t->im_no = mlx_xpm_file_to_image(t->mlx_ptr, t->no, &l, &h);
	t->csno = (unsigned int *)mlx_get_data_addr(t->im_no, &huit, &sl, &un);
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
