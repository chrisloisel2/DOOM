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

void	ft_recuperation(t_t *t)
{
	int	i;
	int un;
	int deux;
	int trois;
	int quatre;

	un = 0;
	deux = 0;
	trois = 0;
	quatre = 0;
	i = ft_strlen(mlx_get_data_addr(t->ptrno, &t->nno, &t->nosl, &un));
	t->tx[0] = malloc(sizeof(unsigned int) * i);
	t->tx[0] = (unsigned int *)mlx_get_data_addr(t->ptrno, &t->nno, &t->nosl, &un);
	i = ft_strlen(mlx_get_data_addr(t->ptrea, &t->nea, &t->easl, &deux));
	t->tx[1] = malloc(sizeof(unsigned int) * i);
	t->tx[1] = (unsigned int *)mlx_get_data_addr(t->ptrea, &t->nea, &t->easl, &deux);
	i = ft_strlen(mlx_get_data_addr(t->ptrwe, &t->nwe, &t->wesl, &trois));
	t->tx[2] = malloc(sizeof(unsigned int) * i);
	t->tx[2] = (unsigned int *)mlx_get_data_addr(t->ptrwe, &t->nwe, &t->wesl, &trois);
	i = ft_strlen(mlx_get_data_addr(t->ptrso, &t->nso, &t->sosl, &quatre));
	t->tx[3] = malloc(sizeof(unsigned int) * i);
	t->tx[3] = (unsigned int *)mlx_get_data_addr(t->ptrso, &t->nso, &t->sosl, &quatre);
}

void	ft_recup(t_t *t)
{
	t->tx = malloc(sizeof(unsigned int *) * 4);
	t->tl = malloc(sizeof(int) * 4);
	t->th = malloc(sizeof(int) * 4);
	t->ptrno = mlx_xpm_file_to_image(t->mlx_ptr, t->no, &t->tl[0], &t->th[0]);
	t->ptrea = mlx_xpm_file_to_image(t->mlx_ptr, t->ea, &t->tl[1], &t->th[1]);
	t->ptrwe = mlx_xpm_file_to_image(t->mlx_ptr, t->we, &t->tl[2], &t->th[2]);
	t->ptrso = mlx_xpm_file_to_image(t->mlx_ptr, t->so, &t->tl[3], &t->th[3]);
	ft_recuperation(t);
}

void	ft_display(t_t *t)
{
	int huit;
	int un;
	int sl;

	un = 1;
	huit = 3;
	sl = t->win_x;
	t->image = mlx_new_image(t->mlx_ptr, t->win_x, t->win_y);
	t->si = (unsigned int *)mlx_get_data_addr(t->image, &huit, &sl, &un);
}

void	ft_start(parse_t *parse, t_t *t)
{
	t->mlx_ptr = mlx_init();
	t->mlx_win = mlx_new_window(t->mlx_ptr, t->win_x, t->win_y, "DOOM");
	ft_display(t);
	ft_recup(t);
	ft_screen(t);
	mlx_hook(t->mlx_win, 2, (1L << 0), &ft_putkey, t);
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
