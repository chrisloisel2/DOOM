/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 22:25:59 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/20 05:43:23 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
#include <fcntl.h>
#include <sys/stat.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <string.h>
# include "ft_printf.h"
#include "get_next_line.h"
# include <mlx.h>

#define W 13
#define ESC 53
#define A 0
#define S 1
#define D 2


#define UP 126
#define DOWN 125
#define RIGHT 124
#define LEFT 123

typedef struct	data_s
{
	void		*mlx_ptr;
	void		*mlx_win;
}				data_t;

typedef struct	map_s
{
	int			max;
	int			y;
	int			x;
	int			error;
	int			tracs;
	int			savex;
	int			savey;
	int			ok;
}				map_t;

typedef struct	parse_s
{
	int			win_x;
	int			win_y;
	int			ccolor;
	int			fcolor;
	int			taby;
	float		rot;
	int			x;
	int			posy;
	int			posx;
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

typedef struct	t_s
{
	float		x;
	float		y;
	float 		rot;
	float		mur;
	float		regard;
}				t_t;


void			ft_screen(t_t *t);
int				ft_check(char str);
int				ft_parse(int fd, parse_t *parse);
void			ft_putcolors(parse_t *parse);
void			ft_init(data_t *data, parse_t *parse);
void			ft_display(data_t *data, parse_t *parse);
void			ft_scoot(parse_t *parse, char *line);
void			ft_tb_made(parse_t *parse);
void			ft_tb_fill(parse_t *parse);
void			ft_two(parse_t *parse, map_t *map);
void			ft_one(parse_t *parse, map_t *map);
void			ft_perfect_cube(parse_t *parse, map_t *map);
int				ft_white_space(char c);
void			ft_search_map(parse_t *parse);
void			ft_map_check(parse_t *parse, map_t *map);

#endif
