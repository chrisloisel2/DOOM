/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 22:25:59 by lchristo          #+#    #+#             */
/*   Updated: 2021/01/05 20:21:57 by lchristo         ###   ########.fr       */
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
	void		*image;
	float		*speed;
	unsigned int 		*si;
	int			demimap;
	double		x;
	double		y;
	double		camerax;
	double		cameray;
	int		casex;
	int		casey;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	float		mur_h;
	float		mur_w;
	float		disty;
	float		distx;
	int			*th;
	int			*tl;
	float		drawEnd;
	float		drawStart;
	float		cam_distance;
	char 		**tb;
	int			maxy;
	int			maxx;
	int			win_x;
	int			win_y;
	int			ccolor;
	int			fcolor;

	double		lineheight;
	double		rdirx;
	double		rdiry;

	int				stepx;
	int				stepy;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	double			sidedistx;
	double			sidedisty;
	char 		*no;
	char 		*so;
	char 		*we;
	char 		*ea;

	char 		*s;
	void		*ptrno;
	void		*ptrso;
	void		*ptrwe;
	void		*ptrea;

	int			nol;
	int			sol;
	int			wel;
	int			eal;

	int			noh;
	int			soh;
	int			weh;
	int			eah;

	int			nosl;
	int			sosl;
	int			wesl;
	int			easl;

	int			side;

	int			nno;
	int			nso;
	int			nwe;
	int			nea;

	unsigned int	*txtno;
	unsigned int	*txtso;
	unsigned int	*txtwe;
	unsigned int	*txtea;

	unsigned int	**tx;
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
void			ft_collomn(t_t *t, int i);
void			ft_ceiling(t_t *t);
void			ft_floor(t_t *t);
int				ft_putkey(int c, t_t *t);
void			ft_print_map(t_t *t);
void			ft_pixel_texture(t_t *t, int y, double x);
void			ft_putpixel(t_t *t, double hauteur, int i, double index);
void			ft_avant(t_t *t, double vitesse);
void			ft_arriere(t_t *t, double vitesse);
void			ft_droite(t_t *t, double vitesse);
void			ft_gauche(t_t *t, double vitesse);
void			ft_rot(t_t *t, double r);

#endif
