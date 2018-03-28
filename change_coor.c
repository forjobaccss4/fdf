/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_coor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:00:24 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/28 15:23:36 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_x(int *tabxy, t_lst *new, int x, int y)
{
	tabxy[2] = new->x + ((x + new->next_x) - y);
	tabxy[3] = new->y + new->int_arr[y / new->next_y][x / new->next_x + 1] \
	* new->z + (x + new->next_x) + y;
	line(new, tabxy);
}

void		draw_y(int *tabxy, t_lst *new, int x, int y)
{
	tabxy[2] = new->x + (x - (y + new->next_y));
	tabxy[3] = new->y + new->int_arr[y / new->next_y + 1][x / new->next_x] \
	* new->z + (y + new->next_y) + x;
	line(new, tabxy);
}

void		trigger_new(t_lst *new)
{
	if (new->trigger == 1)
	{
		new->z = -9;
		new->x = (1720 - 200) / 2;
		new->y = 150;
		new->next_x = ((1720) / 2) / (new->width);
		new->next_y = ((1240) / 2) / (new->height);
	}
	new->trigger = 0;
}

void		bresenham(t_lst *new, int x, int y)
{
	int		tabxy[4];

	tabxy[0] = new->x + (x - y);
	tabxy[1] = new->y + new->int_arr[y / new->next_y][x / new->next_x] * new->z
		+ (x + y);
	if (x / new->next_x < new->width - 1 && y / new->next_y < new->height)
		draw_x(tabxy, new, x, y);
	if (y / new->next_y < new->height - 1 && x / new->next_x < new->width)
		draw_y(tabxy, new, x, y);
}

void		algo(t_lst *new)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	trigger_new(new);
	while (x / new->next_x < new->width || y / new->next_y < new->height - 1)
	{
		if (x / new->next_x == new->width)
		{
			x = 0;
			y += new->next_y;
		}
		bresenham(new, x, y);
		x += new->next_x;
	}
}
