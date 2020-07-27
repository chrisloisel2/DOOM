/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 22:25:59 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/27 07:42:17 by lchristo         ###   ########.fr       */
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
	int			x;
	int			posy;
	int			posx;
	int			y;
	char 		*memory;
}				parse_t;

typedef struct	t_s
{
	void		*mlx_ptr;
	void		*mlx_win;
	int			demimap;
	int			degre;
	float		x;
	float		y;
	float		minray;
	float		maxray;
	float 		rot;
	float		mur;
	float		regard;
	float		cam_distance;
	char 		**tb;
	int			maxy;
	int			maxx;
	int			win_x;
	int			win_y;
	int			ccolor;
	int			fcolor;
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
}				t_t;

void			ft_screen(t_t *t);
int				ft_check(char str);
int				ft_parse(int fd, parse_t *parse, t_t *t);
void			ft_putcolors(t_t *t);
void			ft_init(parse_t *parse, t_t *t);
void			ft_display(t_t *t);
void			ft_scoot(parse_t *parse, char *line, t_t *t);
void			ft_tb_made(parse_t *parse, t_t *t);
void			ft_tb_fill(parse_t *parse, t_t *t);
void			ft_two(parse_t *parse, map_t *map, t_t *t);
void			ft_one(parse_t *parse, map_t *map, t_t *t);
void			ft_perfect_cube(parse_t *parse, map_t *map, t_t *t);
int				ft_white_space(char c);
void			ft_search_map(parse_t *parse, t_t *t);
void			ft_map_check(parse_t *parse, map_t *map, t_t *t);

#endif
