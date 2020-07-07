/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchristo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 02:22:24 by lchristo          #+#    #+#             */
/*   Updated: 2020/07/07 03:14:29 by lchristo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_checkfile(char *line);
int		get_next_line(int fd, char **line);
void	ft_freenull(char **stat);

#endif
