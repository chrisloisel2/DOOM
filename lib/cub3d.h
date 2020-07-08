/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 22:25:59 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/08 05:18:36 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
#include <fcntl.h>
#include <sys/stat.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "ft_printf.h"
#include "get_next_line.h"
# include <mlx.h>

typedef struct	data_s
{
	void		*mlx_ptr;
	void		*mlx_win;
}				data_t;

typedef struct	parse_s
{
	int			win_x;
	int			win_y;
	int			ccolor;
	int			fcolor;
	int			taby;
	int			x;
	int			y;
	int			f1;
	int			f2;
	int			f3;
	int			c1;
	int			c2;
	int			c3;
	char 		*no;
	char 		*so;
	char 		*we;
	char 		*ea;
	char 		*s;
	char 		*memory;
	char 		**tb;
}				parse_t;

int				ft_check(char str);
int				ft_parse(int fd, parse_t *parse);
void			ft_putcolors(parse_t *parse);
void			ft_init(data_t *data, parse_t *parse);
void			ft_display(data_t *data, parse_t *parse);
void			ft_scoot(parse_t *parse, char *line);
void			ft_tb_made(parse_t *parse);
void			ft_tb_fill(parse_t *parse);

#endif
