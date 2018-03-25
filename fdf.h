/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 11:30:18 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/24 11:30:20 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line.h"

typedef struct s_lst
{
	void	*mlx_ptr;
	void	*win_prt;

}				t_lst;

#define roundf(x) floor(x + 0.5f)

char			**ft_strsplit(char const*, char);
char			*ft_strcpy(char*, const char*);
int				ft_atoi(const char*);
size_t			ft_strlen(const char*);
int				key_hook_esc(int);
int				exit_x(void*);
char			**save_map(char*);
char			**save_cycle(int, int, char*, char**);
int				**coordinates(char**);
int				len_d_arr(char**);
char			**coordinates_in_one_line(char*);
void			free_double_array(char**);
int				len_of_map(char*);
void			drow(char**, int**, t_lst*);
void			drow_helper(int*, char**, t_lst*);
int				main(int, char**);

void line(t_lst*, int*, int, int);
#endif