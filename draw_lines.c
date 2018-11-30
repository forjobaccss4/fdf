/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:00:42 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/28 15:18:10 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	line_helper(t_lst *win, int *xyx1y1, int x_y[5])
{
	int x;
	int y;
	int d;

	x = xyx1y1[0];
	y = xyx1y1[1];
	d = -x_y[2];
	x_y[4]++;
	while (x_y[4]--)
	{
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, 0x00ffae);
		x += x_y[0];
		d += 2 * x_y[3];
		if (d > 0)
		{
			d -= 2 * x_y[2];
			y += x_y[1];
		}
	}
}

void	line_helper_continue(t_lst *win, int *xyx1y1, int x_y[5])
{
	int x;
	int y;
	int d;

	x = xyx1y1[0];
	y = xyx1y1[1];
	d = -x_y[3];
	x_y[4]++;
	while (x_y[4]--)
	{
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, 0x00ffae);
		y += x_y[1];
		d += 2 * x_y[2];
		if (d > 0)
		{
			d -= 2 * x_y[3];
			x += x_y[0];
		}
	}
}

void	line(t_lst *win, int *xyx1y1)
{
	int x_y[5];

	x_y[0] = (xyx1y1[2] - xyx1y1[0] >= 0 ? 1 : -1);
	x_y[1] = (xyx1y1[3] - xyx1y1[1] >= 0 ? 1 : -1);
	x_y[2] = abs(xyx1y1[2] - xyx1y1[0]);
	x_y[3] = abs(xyx1y1[3] - xyx1y1[1]);
	x_y[4] = fmax(x_y[2], x_y[3]);
	if (x_y[4] == 0)
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, xyx1y1[0], \
				xyx1y1[1], 0x00ffae);
	if (x_y[3] <= x_y[2])
		line_helper(win, xyx1y1, x_y);
	else
		line_helper_continue(win, xyx1y1, x_y);
}
