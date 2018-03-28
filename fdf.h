/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:20:52 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/28 15:23:12 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

typedef	struct	s_lst
{
	int			trigger;
	int			**int_arr;
	int			width;
	int			height;
	int			counter;
	int			z;
	int			x;
	int			y;
	int			next_x;
	int			next_y;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_lst;

void			err_msg(char *str);
void			free_d_arr(char **arr);
void			free_structure(t_lst *lst);
void			read_map(t_lst *lst, int fd);
void			window_creator(t_lst *lst, char *smth);
void			algo(t_lst *lst);
void			line(t_lst *win, int *xyx1y1);
#endif
