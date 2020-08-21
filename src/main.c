/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 22:01:44 by lchristo          #+#    #+#             */
/*   Updated: 2020/08/20 13:53:21 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/cub3d.h"

void	ft_recup(t_t *t)
{
	int huit;
	int un;
	int sl;

	huit = 3;
	un = 1;
	sl = 0;
	t->mlx_ptr = mlx_init();
	t->mlx_win = mlx_new_window(t->mlx_ptr, t->win_x, t->win_y, "DOOM");
	t->ptrno = mlx_xpm_file_to_image(t->mlx_ptr, t->no, &t->nol, &t->noh);
	t->ptrso = mlx_xpm_file_to_image(t->mlx_ptr, t->so, &t->sol, &t->soh);
//	txt->we = mlx_xpm_file_to_image(t->mlx_ptr, t->we, &txt->wel, &txt->weh);
//	txt->ea = mlx_xpm_file_to_image(t->mlx_ptr, t->ea, &txt->eal, &txt->eah);

	t->strno = (unsigned int *)mlx_get_data_addr(t->ptrno, &t->nno, &t->nosl, &un);
	t->strso = (unsigned int *)mlx_get_data_addr(t->ptrso, &t->nso, &t->sosl, &un);
//	txt->strwe = (unsigned int *)mlx_get_data_addr(txt->we, &txt->nwe, &txt->wesl, &un);
//	txt->strea = (unsigned int *)mlx_get_data_addr(txt->ea, &txt->nea, &txt->easl, &un);
}

void	ft_speed(t_t *t)
{
	int i;

	i = 0;
	while (i <= t->win_x)
	{
		t->speed[i] = 0;
		i++;
	}
}

void	ft_start(parse_t *parse, t_t *t)
{
	ft_recup(t);
	t->mur_h = t->win_y / 10;
	t->speed = malloc(sizeof(int) * t->win_x);
	ft_speed(t);
	t->cam_distance = (t->win_x/2) / tan(20);
	ft_display(t);
	ft_screen(t);
	mlx_hook(t->mlx_win, 2, 0, ft_putkey, t);
	mlx_loop(t->mlx_ptr);
}

int		main(int argc, char **argv)
{
	t_t			t;
	txt_t		txt;
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
