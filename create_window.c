/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:00:34 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/28 12:00:36 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				exit_x(void *param)
{
	param = NULL;
	exit(1);
	return (0);
}

int				keyboard(int keycode, t_lst *new)
{
	if (keycode == 53)
	{
		mlx_destroy_window(new->mlx_ptr, new->win_ptr);
		exit(1);
	}
	return (1);
}

void			window_creator(t_lst *new, char *name)
{
	new->mlx_ptr = mlx_init();
	new->win_ptr = mlx_new_window(new->mlx_ptr, 1720, 1240, name);
	algo(new);
	mlx_key_hook(new->win_ptr, keyboard, new);
	mlx_hook(new->win_ptr, 17, 1L << 0, exit_x, NULL);
	mlx_loop(new->mlx_ptr);
}
