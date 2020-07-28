/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 22:01:44 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/28 16:13:42 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

int		ft_putkey(int c, t_t *t)
{
	t->tb[(int)t->y][(int)t->x] = '0';
	if (c == W && t->tb[(int)t->y - 1][(int)t->x] == '0')
		t->y -= 1;
	if (c == A && t->tb[(int)t->y][(int)t->x - 1] == '0')
		t->x -= 1;
	if (c == S && t->tb[(int)t->y + 1][(int)t->x] == '0')
		t->y += 1;
	if (c == D && t->tb[(int)t->y][(int)t->x + 1] == '0')
		t->x += 1;
	if (c == RIGHT)
		t->rot -= (float)(40 * M_PI / 180);	
	if (c == LEFT)
		t->rot += (float)(40 * M_PI / 180);	
	if (t->rot > (float)(2 * M_PI))
		t->rot -= (float)(2*M_PI);
	if (t->rot < (float)(0))
		t->rot += (float)(2*M_PI);
	t->tb[(int)t->y][(int)t->x] = 'O';
	t->degre = t->rot * (180/M_PI);
	ft_screen(t);
	return (0);
}

void	ft_start(parse_t *parse, t_t *t)
{
	t->mlx_ptr = mlx_init();
	t->mlx_win = mlx_new_window(t->mlx_ptr, t->win_x, t->win_y, "DOOM");
	ft_screen(t);
	ft_display(t);
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
