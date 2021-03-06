# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchristo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/06 21:59:06 by lchristo          #+#    #+#              #
#    Updated: 2021/01/13 09:48:12 by lchristo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC = 		src/main.c\
			src/ft_printf.c\
			src/ft_puthexa.c\
			src/ft_putstr.c\
			src/ft_get.c\
			src/ft_star.c\
			src/ft_atoi.c\
			src/ft_get_str.c\
			src/ft_strjoin.c\
			src/ft_get_numbers.c\
			src/ft_strlen.c\
			src/ft_dot.c\
			src/ft_calculus.c\
			src/ft_alpha.c\
			src/ft_minus.c\
			src/ft_zero.c\
			src/ft_flag.c\
			src/get_next_line.c\
			src/get_next_line_utils.c\
			src/ft_parsing.c\
			src/ft_init.c\
			src/ft_scoot.c\
			src/ft_maps.c\
			src/ft_screen.c\
			src/ft_collomn.c\
			src/ft_keys.c\
			src/ft_texture.c\
			src/ft_move.c\
			src/ft_dda.c


MLX = minilibx

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror -c

OPTION = -03 -Wall -Wextra -Werror 

all: $(NAME)

$(NAME):
	cc  -o $(NAME) -I /usr/local/include $(SRC) -L /usr/local/lib $(MLXFLAGS)

debug:
	cc -g3 -o $(NAME) -I /usr/local/include $(SRC) -L /usr/local/lib $(MLXFLAGS)

clean:
	/bin/rm -f $(OBJ) $(OBJBONUS)

fclean: clean
	/bin/rm -f $(NAME)

re:	fclean all
